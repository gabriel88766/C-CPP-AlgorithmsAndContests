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
        ll x, y, z, k;
        cin >> x >> y >> z >> k;
        vector<ll> divs;
        int mx = max(x, max(y, z));
        for(int i=1;i<=mx;i++){
            if(!(k % i)) divs.push_back(i);
        }
        ll ans = 0;
        for(auto a : divs){
            if(a > x) break;
            for(auto b : divs){
                if(b > y) break;
                if(!(k % (a*b))){
                    ll c = k/(a*b);
                    if(c > z) continue;
                    ans = max(ans, (z-c+1)*(y-b+1)*(x-a+1));
                }
            }
        }
        cout << ans << "\n";
        
    }
}
