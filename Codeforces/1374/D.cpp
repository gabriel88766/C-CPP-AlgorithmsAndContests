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
        map<ll,ll> mp;
        for(int i=0;i<n;i++){
             int aux;
             cin >> aux;
             ll cg = (k - aux % k) % k;
             if(cg)mp[cg]++;
        }
        ll ans = 0;
        for(auto x : mp){
            ans = max(ans, x.first + (x.second-1)*k + 1);
        }
        cout << ans << "\n";
    }
}
