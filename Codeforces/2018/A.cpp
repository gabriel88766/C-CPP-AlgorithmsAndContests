#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        ll s = 0;
        for(int i=0;i<n;i++) s += v[i];
        ll me = *max_element(v.begin(), v.end());
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ll ms =  (i - (s % i))%i;
            if(ms <= k){
                ll d = (s + k)/i;
                if(d >= me) ans = i;
            }
        }
        cout << ans << "\n";
    }
}   
