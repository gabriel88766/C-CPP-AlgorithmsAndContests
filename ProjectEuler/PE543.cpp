#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 22e6;
bool p[N]; // 0 if prime, 1 if not prime
int cnt[N];
vector<ll> primes;
void sieve(){
    primes.push_back(0);
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            cnt[i] = 1;
            primes.push_back(i);
        }
        cnt[i] += cnt[i-1];
    }
}

ll y;
vector<tuple<ll, ll, ll>> qrs;

struct Bit{
    vector<int> bit;
    int n;
    Bit(int sz){
        n = sz;
        bit.resize(sz+1);
    }
    int query(int b){ // sum in range [1, b]
        int ans = 0;
        for(int i = b; i > 0; i -= i & -i){
            ans += bit[i];
        }
        return ans;
    }
    void add(int b){ //add value to position b
        for(int i = b; i <= n; i += i & -i){
            bit[i]++;
        }
    } 
};


ll fphi2(ll n, ll a, int s){
    if(a == 0) return n; //sum 1, n if sum
    else{
        if(n < primes[a]) return 0;
        if((a-1) && n/primes[a] <= y){
            qrs.push_back({n/primes[a], a-1, -s});
            return fphi2(n, a-1, s);
        }else
        return fphi2(n, a-1, s) - fphi2(n/primes[a], a-1, -s); //multiply here if sum
    }
}
ll cntp(ll n){
    if(n < N) return cnt[n];
    ll cy = pow(n, 0.385);
    ll a = upper_bound(primes.begin(), primes.end(), cy) - primes.begin();
    y = n/primes[a]+1;
    qrs.resize(0);
    ll ans = fphi2(n, a, 1);
    sort(qrs.begin(), qrs.end(), [&](tuple<ll, ll, ll> &a, tuple<ll, ll, ll> &b){
        auto [n1, a1, s1] = a;
        auto [n2, a2, s2] = b;
        return a1 < a2;
    });
    Bit b(y);
    int p = 1;
    vector<char> vis(y+1, false);
    for(auto [n, a, s] : qrs){
        while(p <= a){
            for(int i=primes[p];i<=y;i+=primes[p]){
                if(!vis[i]){
                    b.add(i);
                    vis[i] = true;
                }
            }
            p++;
        }
        if(s == 1) ans += n - b.query(n);
        else ans -= n - b.query(n);
    }
    ans += a - 1;
    p = lower_bound(primes.begin(), primes.end(), n/primes[a+1]) - primes.begin();
    for(int i=a+1;i<primes.size();i++){
        while(primes[i] * primes[p] > n) p--;
        if(p < i) break;
        ans -= p-i+1; //prefix sum if sum.
    }
    return ans;
}

ll fib[45];

ll sum(ll ft, ll lt){
    ll n = (ft - lt)/2 + 1;
    ll ans = n * (ft + lt);
    return ans / 2;
}

ll solve(int n){
    if(n == 2) return 1;
    else if(n == 3) return 2;
    ll ans = 0;
    //for k = 1;
    ans += cntp(n);
    //for k = 2;
    ans += n/2 - 1; //even numbers
    ans += cntp(n-2) - 1; //odd numbers
    //for k = 3, (n-6+1), for k = 4 (n-8+1);
    ll ft = n - 6 + 1;
    ll lt = (ft % 2 ? 1 : 2);
    ans += sum(ft, lt);
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    fib[1] = 1;
    for(int i=2;i<=44;i++) fib[i] = fib[i-1] + fib[i-2];
    ll ans = 0;
    for(int i=3;i<=44;i++){
        ans += solve(fib[i]);
    }
    cout << ans << "\n";
}
