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
        int n, k;
        cin >> n >> k;
        if(k > 32){
            cout << "0\n";
        }else{
            vector<vector<ll>> v = {{1,1}, {1,0}}, aux;
            aux = v;
            for(int i=2;i<=k-2;i++){
                auto x = v;
                v[0][0] = x[0][0]*aux[0][0]+x[0][1]*aux[1][0];
                v[0][1] = x[0][0]*aux[0][1]+x[0][1]*aux[1][1];
                v[1][0] = x[1][0]*aux[0][0]+x[1][1]*aux[1][0];
                v[1][1] = x[1][0]*aux[0][1]+x[1][1]*aux[1][1];
            }
            int ans = 0;
            for(int i=0;i<=n;i++){  
                ll x = v[0][1]*i;
                x = n-x;
                if(x % v[0][0] == 0 && x/v[0][0] >= i) ans++;
            }
            cout << ans << "\n";
        }
    }
}
