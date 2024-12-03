#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char rv[] = {'U', 'D', 'L', 'R'};
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
        vector<vector<char>> gr(n+2, vector<char>(m+2));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> gr[i][j];
            }
        }
        vector<vector<bool>> vis(n+2, vector<bool>(m+2, false));
        vector<vector<char>> vis2(n+2, vector<char>(m+2, false));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(gr[i][j] == '?'){
                    if(gr[i][j-1] == '?' || gr[i][j+1] == '?' || gr[i+1][j] == '?' || gr[i-1][j] == '?'){
                        vis[i][j] = 1;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((!vis2[i][j]) && gr[i][j] != '?'){
                    vector<pair<int,int>> vp;
                    pair<int,int> cur = {i, j};
                    while(!vis2[cur.first][cur.second]){
                        if(cur.first > 0 && cur.first <= n && cur.second > 0 && cur.second <= m){
                            vis2[cur.first][cur.second] = 1;
                            vp.push_back(cur);
                            auto [a, b] = cur;
                            if(gr[a][b] == '?') break;
                            if(vis[a][b]) break;
                            if(gr[a][b] == 'U') cur.first--;
                            else if(gr[a][b] == 'D') cur.first++;
                            else if(gr[a][b] == 'L') cur.second--;
                            else cur.second++;
                        }else break;
                    }
                    if(gr[cur.first][cur.second] == '?' || vis[cur.first][cur.second] || vis2[cur.first][cur.second] == 1){
                       
                        for(auto [a, b] : vp){ 
                            vis[a][b] = 1;
                            if(gr[a][b-1] == '?') vis[a][b-1] = true;
                            if(gr[a][b+1] == '?') vis[a][b+1] = true;
                            if(gr[a-1][b] == '?') vis[a-1][b] = true;
                            if(gr[a+1][b] == '?') vis[a+1][b] = true;
                        }
                        
                    }
                    for(auto [a,b] : vp) vis2[a][b] = 2;
                }
            }
        }
        
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]) ans++;
            }
        }
        cout << ans << "\n";
    }
}
 