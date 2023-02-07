#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {-1,0,1,-1,1,-1,0,1};
int dy[] = {1,1,1,0,0,-1,-1,-1};


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
        vector<vector<char>> grid(n+2, vector<char>(m+2,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> grid[i][j];
            }
        }
        bool ok = true;
        for(int i=1;i<=n;i++){
            if(!ok) break;
            for(int j=1;j<=m;j++){
                if(!ok) break;
                if(grid[i][j] == '*'){
                    //inline bfs
                    queue<pair<int,int>> q;
                    vector<pair<int,int>> pairs;
                    q.push({i, j});
                    grid[i][j] = '.';
                    while(!q.empty()){
                        auto u = q.front();
                        pairs.push_back(u);
                        q.pop();
                        for(int k=0;k<8;k++){
                            if(grid[u.first + dx[k]][u.second + dy[k]] == '*'){
                                q.push({u.first + dx[k], u.second + dy[k]});
                                grid[u.first+dx[k]][u.second+dy[k]] = '.';
                            }
                        }
                    }
                    if(pairs.size() != 3){
                        ok = false;
                    }
                    else{
                        int xmax, xmin, ymax, ymin;
                        xmax = xmin = pairs[0].first;
                        ymax = ymin = pairs[0].second;
                        for(auto u : pairs){
                            xmax = max(xmax, u.first);
                            xmin = min(xmin, u.first);
                            ymax = max(ymax, u.second);
                            ymin = min(ymin, u.second);
                        }
                        if(xmax > (xmin+1)) ok = false;
                        if(ymax > (ymin+1)) ok = false;
                    } 
                }
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";

    }
}
