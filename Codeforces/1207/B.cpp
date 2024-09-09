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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> vis(n, vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> v[i][j];
    vector<pair<int,int>> ans;
    bool ok = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i < n-1 && j < m-1 && v[i][j] && v[i][j+1] && v[i+1][j] && v[i+1][j+1]){
                vis[i][j] = vis[i+1][j] = vis[i][j+1] = vis[i+1][j+1] = true;
                ans.push_back({i, j});
            }
            if(v[i][j] && (!(vis[i][j]))){
                ok = false;
            }
        }
    }
    if(ok){
        cout << ans.size() << "\n";
        for(auto [x, y] : ans) cout << x+1 << " " << y+1 << "\n";
    }else cout << "-1\n";
}
