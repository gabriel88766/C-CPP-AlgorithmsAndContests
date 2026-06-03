#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool vis2[26];
int d[2005][2005];
char gr[2005][2005];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(d, 63, sizeof(d));
    memset(gr, '#', sizeof(gr));
    int h, w;
    cin >> h >> w;
    queue<pair<int, int>> q;
    vector<vector<pair<int, int>>> ag(26);
    pair<int, int> G;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
            if(gr[i][j] == 'S') {q.push({i, j}); d[i][j] = 0;}
            if(gr[i][j] == 'G') G = {i, j};
            if(gr[i][j] >= 'a' && gr[i][j] <= 'z') ag[gr[i][j]-'a'].push_back({i, j});
        }
    }
    while(q.size()){
        auto [ci, cj] = q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int di = ci + dx[k];
            int dj = cj + dy[k];
            if(gr[di][dj] != '#' && d[di][dj] > d[ci][cj] + 1){
                d[di][dj] = d[ci][cj] + 1;
                q.push({di, dj});
            }
        }
        if(gr[ci][cj] >= 'a' && gr[ci][cj] <= 'z' && vis2[gr[ci][cj]-'a'] == false){
            vis2[gr[ci][cj]-'a'] = true;
            for(auto [di, dj] : ag[gr[ci][cj]-'a']){
                if(gr[di][dj] != '#' && d[di][dj] > d[ci][cj] + 1){
                    d[di][dj] = d[ci][cj] + 1;
                    q.push({di, dj});
                }
            }
        }
    }
    if(d[G.first][G.second] == INF_INT) cout << "-1\n";
    else cout << d[G.first][G.second] << "\n";
}   
