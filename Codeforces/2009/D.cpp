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
        vector<vector<bool>> in(n+1, vector<bool>(2, false));
        for(int i=1;i<=n;i++){
            int x, y;
            cin >> x >> y;
            in[x][y] = true;
        }
        ll ans = 0;
        for(int i=0;i<=n;i++){
            if(in[i][0] && in[i][1]){
                ans += n - 2;
            }
        }
        for(int i=1;i<=n-1;i++){
            for(int j=0;j<=1;j++){
                if(in[i][j] && in[i-1][j^1] && in[i+1][j^1]) ans++;
            }
        }
        cout << ans << "\n";
    }    
}
