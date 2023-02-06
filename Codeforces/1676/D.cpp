#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> v[i][j];
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curs = v[i][j];
                for(int k=1;k<min(n,m);k++){
                    if((i+k) < n  && (j+k) < m) curs += v[i+k][j+k];
                    if((i-k) >= 0 && (j+k) < m) curs += v[i-k][j+k];
                    if((i-k) >= 0 && (j-k) >= 0) curs += v[i-k][j-k];
                    if((i+k) < n && (j-k) >= 0) curs += v[i+k][j-k];
                }
                ans = max(ans, curs);
            }
        }
        cout << ans << "\n";
    }
}
