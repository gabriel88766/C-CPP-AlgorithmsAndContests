#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+5;
int p[N]; // 0 if prime, 1 if not prime
vector<ll> primes;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            primes.push_back(i);
        }
    }
}

ll maxv = 2e9;
map<ll,ll> mp;
int cnt = 0;
void generate(vector<ll> &v, int cur, ll val, int cnt){
    mp[val] = cnt;
    for(int i=cur+1;i<v.size();i++){
        if(val*v[i] <= maxv){
            generate(v, i, val*v[i], cnt+1);
        }
    }
}
int C = 1000;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int a, b, k;
    cin >> a >> b >> k;
    bool ok = true;
    for(int i=2;i*i<=k;i++){
        if(!(k % i)){
            ok = false;
            break;
        }
    }
    if(!ok){
        cout << "0\n";
        return 0;
    }
    if(k >= 45000){
        if(a <= k && b >= k) cout << "1\n";
        else cout << "0\n";
    }else{
        vector<ll> v;
        for(auto x : primes){
            if(x < k) v.push_back(x);
            else break;
        }
        maxv /= k;
        generate(v, -1, 1, 0);
        int l = (a-1)/k + 1, r = b/k;
        ll ans = 0;
        for(auto x : mp){
            if(x.second % 2){
                ans -= r/x.first - (l-1)/x.first;
            }else{
                ans += r/x.first - (l-1)/x.first;
            }
        }
        cout << ans << "\n";
    }

}
