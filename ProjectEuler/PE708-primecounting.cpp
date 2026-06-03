#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const ll N = 5e7+5;
bool pr[N];
int cnt[N];
unordered_map<ll, ll> cnt2;
vector<ll> primes;
void sieve(int n){
    primes.push_back(0);
    pr[1] = 1;
    for(ll i=2;i<=n;i++){
        if(!pr[i]){
            for(ll j = i*i;j<=n;j+=i) pr[j] = 1;
            cnt[i] = 1;
            primes.push_back(i);
        }
        cnt[i] += cnt[i-1];
    }
}

ll calc(ll n, ll p = 2e7){ 
    if(n == 1) return 0; 
    if(p*p >= n && n < N) return cnt[n]; 
    ll ans = n; 
    ans -= 1;
    ll sqt = sqrt(n); 
    while(sqt*sqt>n) sqt--; 
    while((sqt+1)*(sqt+1) <= n) sqt++; 
    for(ll i=2;i<=min(p, sqt);i++){ 
        if(!pr[i]){ 
            ans -= (calc(n/i, i-1) - cnt[i-1]); 
        } 
    } return ans; 
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


ll fphi2(ll n, ll a, ll s){
    if(a == 0) return n; //sum 1, n if sum
    else{
        if(n < primes[a]) return 1;
        if(primes[a] * primes[a] >= n && n < N) return cnt[n] - cnt[primes[a]] + 1;
        if((a-1) && n/primes[a] <= y){
            qrs.push_back({n/primes[a], a-1, -s});
            return fphi2(n, a-1, s);
        }else
        return fphi2(n, a-1, s) - fphi2(n/primes[a], a-1, -s); //multiply here if sum
    }
}
ll cntp(ll n){
    if(n < N) return cnt[n];
    if(cnt2.count(n)) return cnt2[n];
    ll cy = pow(n, 0.34);
    ll a = upper_bound(primes.begin(), primes.end(), cy) - primes.begin();
    y = 10'000'000LL;
    ll ans = 0;
    int p = lower_bound(primes.begin(), primes.end(), n/primes[a+1]) - primes.begin();
    if(primes[p] * primes[a] >= n){
        for(int i=a+1;i<primes.size();i++){
            if(n/primes[i] < primes[i]) break;
            while(primes[i] * primes[p] > n) p--;
            ans -= p - i + 1;
        } 
    }else{
        for(int i=a+1;i<primes.size();i++){
            if(n/primes[i] < primes[i]) break;
            ans -= cntp(n/primes[i]) - i + 1;
        }
    }
    qrs.clear();
    ans += fphi2(n, a, 1);
    ans += a - 1;
    
    
    sort(qrs.begin(), qrs.end(), [&](tuple<ll, ll, ll> &a, tuple<ll, ll, ll> &b){
        auto [n1, a1, s1] = a;
        auto [n2, a2, s2] = b;
        return a1 < a2;
    });
    Bit b(y);
    p = 1;
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

    return cnt2[n] = ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n = 10'000'000'000'000LL;
    sieve(N-1);
    // ll ans = calc(n);
    cout << cntp(n) << "\n";
    
    // cout << calc(n) << " " << cntp(n) << "\n";
}
