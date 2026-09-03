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
    int h, w, k;
    cin >> h >> w >> k;
    vector<bool> sc(w+1, true), sr(h+1, true);
    vector<string> gr(h+1);
    for(int i=1;i<=h;i++){
        cin >> gr[i];
        gr[i] = " " + gr[i];
        for(int j=1;j<=w;j++){
            if(gr[i][j] == '#') sr[i] = sc[j] = false;
        }
    }
    vector<vector<int>> d(h+1, vector<int>(w+1, INF_INT));
    queue<pair<int, int>> qp;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(sr[i] && sc[j]){
                qp.push({i, j});
                d[i][j] = 0;
            }
        }
    }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    while(qp.size()){
        auto [x, y] = qp.front();
        qp.pop();
        for(int k=0;k<4;k++){
            int cx = x + dx[k];
            int cy = y + dy[k];
            if(cx >= 1 && cx <= h && cy >= 1 && cy <= w && gr[cx][cy] == '.'){
                if(d[cx][cy] > d[x][y] + 1){
                    d[cx][cy] = d[x][y] + 1;
                    qp.push({cx, cy});
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(d[i][j] <= k) ans++;
        }
    }
    cout << ans << "\n";
}
