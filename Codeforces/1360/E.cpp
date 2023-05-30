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
        vector<pair<int,int>> list;
        vector<vector<bool>> vis(n, vector<bool> (n, false)), val(n, vector<bool> (n, false));
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char c;
                cin >> c;
                if(c == '1'){
                    list.push_back({i, j});
                    val[i][j] = true;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(val[n-1][i]){
                q.push({n-1, i});
                vis[n-1][i] = true;
            }
            if(i != (n-1) && val[i][n-1]){
                 q.push({i, n-1});
                 vis[i][n-1] = true;
            }
        }
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            if(u.first > 0 && val[u.first-1][u.second]){
                if(!vis[u.first-1][u.second]){
                     q.push({u.first-1, u.second});
                     vis[u.first-1][u.second] = true;
                }
            }
            if(u.second > 0 && val[u.first][u.second - 1]){
                if(!vis[u.first][u.second-1]){
                    q.push({u.first, u.second-1});
                    vis[u.first][u.second-1] = true;
                }
                
            }
        }
        bool ok = true;
        for(auto x: list){
            if(!vis[x.first][x.second]) ok = false;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
