#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+200;
int p[N]; // 0 if prime, 1 if not prime
vector<ll> pr;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            pr.push_back(i);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    ll n;
    cin >> n;
    ll ans = 0;
    for(auto x : pr){
        if(x == 2) continue;
        if(2*x*x*x <= n){
            if(x*x*x <= n/x){
                auto it = lower_bound(pr.begin(), pr.end(), x);
                ans += it - pr.begin();
            }else{
                auto it = upper_bound(pr.begin(), pr.end(), n/(x*x*x));
                assert(it != pr.end());
                assert(*it * x * x * x > n);
                --it;
                assert(*it * x * x * x <= n);
                ++it;
                ans += it - pr.begin();
            }
            
        }else break;
    }
    cout << ans << "\n";
}
