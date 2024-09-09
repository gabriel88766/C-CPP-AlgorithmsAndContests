#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

pair<int,int> pos[105];
pair<int,int> dp[11][11][3];
pair<int,int> lst[3];
int dkx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dky[] = {1, -1, 1, -1, 2, -2, 2, -2};
int dbx[] = {1, -1, 1, -1};
int dby[] = {1, 1, -1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin >> x;
            pos[x] = {i, j};
        }
    }
    lst[0] = lst[1] = lst[2] = {0, 0};
    for(int i=1;i<n*n;i++){
        //i -> i+1;
        memset(dp, 63, sizeof(dp));
        pair<int,int> src = pos[i];
        pair<int,int> dst = pos[i+1];
        for(int j=0;j<3;j++) dp[src.first][src.second][j] = lst[j];
        queue<pair<int,int>> q;
        q.push(src);
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            //fix
            pair<int,int> lv = min(dp[u.first][u.second][0], min(dp[u.first][u.second][1], dp[u.first][u.second][2]));
            for(int j=0;j<3;j++) dp[u.first][u.second][j] = min(dp[u.first][u.second][j], make_pair(lv.first+1, lv.second+1));
            //rook
            for(int j=1;j<=n;j++){
                if(dp[j][u.second][0] > make_pair(dp[u.first][u.second][0].first + 1, dp[u.first][u.second][0].second)){
                    dp[j][u.second][0] = make_pair(dp[u.first][u.second][0].first + 1, dp[u.first][u.second][0].second);
                    q.push({j, u.second});
                }
            }
            for(int j=1;j<=n;j++){
                if(dp[u.first][j][0] > make_pair(dp[u.first][u.second][0].first + 1, dp[u.first][u.second][0].second)){
                    dp[u.first][j][0] = make_pair(dp[u.first][u.second][0].first + 1, dp[u.first][u.second][0].second);
                    q.push({u.first, j});
                }
            }
            //knight
            for(int j=0;j<8;j++){
                if(u.first + dkx[j] > n || u.first + dkx[j] <= 0) continue;
                if(u.second + dky[j] > n || u.second + dky[j] <= 0) continue;
                if(dp[u.first+dkx[j]][u.second+dky[j]][1] > make_pair(dp[u.first][u.second][1].first + 1, dp[u.first][u.second][1].second)){
                    dp[u.first+dkx[j]][u.second+dky[j]][1] = make_pair(dp[u.first][u.second][1].first + 1, dp[u.first][u.second][1].second);
                    q.push({u.first+dkx[j], u.second+dky[j]});
                }
            }
            //bishop
            for(int j=0;j<4;j++){
                for(int k=1;k<=n;k++){
                    if(u.first + k*dbx[j] > n || u.first + k*dbx[j] <= 0) continue;
                    if(u.second + k*dby[j] > n || u.second + k*dby[j] <= 0 ) continue;
                    if(dp[u.first+k*dbx[j]][u.second+k*dby[j]][2] > make_pair(dp[u.first][u.second][2].first + 1, dp[u.first][u.second][2].second)){
                        dp[u.first+k*dbx[j]][u.second+k*dby[j]][2] = make_pair(dp[u.first][u.second][2].first + 1, dp[u.first][u.second][2].second);
                        q.push({u.first+k*dbx[j], u.second+k*dby[j]});
                    }
                }
            }
        }
        for(int j=0;j<3;j++) lst[j] = dp[dst.first][dst.second][j];
    }
    pair<int,int> ans = min(lst[0], min(lst[1], lst[2]));
    cout << ans.first << " " << ans.second << "\n";

}
