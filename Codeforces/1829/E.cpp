#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<bool>> vis(n+2, vector<bool> (m+2,false));
        vector<vector<int>> v(n+2, vector<int> (m+2, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> v[i][j];
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(v[i][j] && !vis[i][j]){
                    int cur = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j] = true;
                    while(!q.empty()){
                        auto u = q.front();
                        q.pop();
                        cur += v[u.first][u.second];
                        for(int k=0;k<4;k++){
                            if(v[u.first+dx[k]][u.second+dy[k]] && !vis[u.first+dx[k]][u.second+dy[k]]){
                                vis[u.first+dx[k]][u.second+dy[k]] = true;
                                q.push({u.first+dx[k], u.second+dy[k]});
                            }
                        }
                    }
                    ans = max(ans, cur);
                }
            }
        }
        cout << ans << "\n";
    }
}
