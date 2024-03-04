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
    //relative move
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> rk(n, vector<int>(m));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> rk[i][j];
        vector<vector<int>> d(n, vector<int> (m, INF_INT));
        d[0][0] = 0;
        queue<pair<int,int>> q;
        q.push({0, 0});
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            int dx1 = (x + 2) % n;
            int dy1 = y;
            int dx2 = (x + 1) % n;
            int dy2 = (y + 1) % m;
            if(!rk[dx1][dy1] && !rk[dx2][dy1] && d[dx1][dy1] > d[x][y] + 1){
                d[dx1][dy1] = d[x][y] + 1;
                q.push({dx1, dy1});
            }
            if(!rk[dx2][dy2] && d[dx2][dy2] > d[x][y] + 1){
                d[dx2][dy2] = d[x][y] + 1;
                q.push({dx2, dy2});
            }
        }
        int ans = INF_INT;
        for(int i=0;i<n;i++){
            int eq = (i + 1) % n;
            if(d[i][m-1] != INF_INT){
                int cur = 0;
                if(d[i][m-1] % n <= eq) cur = d[i][m-1] + eq - d[i][m-1] % n;
                else cur = d[i][m-1] + n - d[i][m-1] % n + eq;
                ans = min(ans, cur);
            }
            
        }
        if(ans == INF_INT) cout << "-1\n";
        else cout << ans << "\n";
    }
}
