#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 316228;
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

ll maxv;
map<ll,ll> mp;
ll cx = 0;
ll ans = 0;
void generate(vector<ll> &v, int cur, ll val, int cnt){
    //mp[val] = cnt;
    cx++;
    for(int i=cur+1;i<v.size();i++){
        if(val*v[i] <= maxv){
            generate(v, i, val*v[i], cnt+1);
        }else break;
    }
}


ll cp(ll x){
    ll ans = 0;
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    ll n;
    //cin >> n;
    
    for(ll i = 2; i*i*i <= n; i++){
        if(p[i]) ans++;
    }
    int c = 0;
    for(auto x : primes){
        if(n/x <= x) break;
        c++;
        ans += cp(n/x) - c;
    }
    cout << ans << "\n";
}
