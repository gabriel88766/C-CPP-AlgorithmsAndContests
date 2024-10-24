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
        int n;
        cin >> n;
        vector<vector<ll>> v(n,vector<ll>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> v[i][j];
            }
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            ll mv = 0;
            for(int u=0;i+u<n;u++){
                if(v[i+u][u] < 0) mv = min(mv, v[i+u][u]);
            }
            ans += abs(mv);
        }
        for(int j=1;j<n;j++){
            ll mv = 0;
            for(int u=0;j+u<n;u++){
                if(v[u][j+u] < 0) mv = min(mv, v[u][j+u]);
            }
            ans += abs(mv);
        }
        cout << ans << "\n";
    }
}
