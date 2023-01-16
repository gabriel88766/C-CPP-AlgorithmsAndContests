#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 1e3+3;
int dist1[N][N], dist2[N][N]; //dist1, each cell to monster, dist2 each cell to A, dist2 must be lower than dist1 or the cell is unreachable, -1 is prohibited
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char cmr[] = {'R', 'D', 'L', 'U'}; 
char p[N][N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    memset(dist1, 63, sizeof(dist1));
    memset(dist2, 63, sizeof(dist2));
    
    int n, m;
    pair<int,int> posa;
    cin >> n >> m;

    queue<pair<int,int>> qm, qa;
    for(int i=0;i<=1001;i++){
        dist1[0][i] = dist2[0][i] = -1;
        dist1[n+1][i] = dist2[n+1][i] = -1;
        dist1[i][0] = dist2[i][0] = -1;
        dist1[i][m+1] = dist2[i][m+1] = -1;
    }
    for(int i=1;i<=n;i++){
        
        for(int j=1;j<=m;j++){
            char c;
            cin >> c;
            if(c == '#'){dist1[i][j] = dist2[i][j] = -1;}
            if(c == 'M'){dist1[i][j] = 0; qm.push({i, j});}
            if(c == 'A'){dist2[i][j] = 0; qa.push({i, j}); posa = {i, j};}
        }
    }
    
    
    //bfs monsters 
    while(!qm.empty()){
        auto ui = qm.front().first;
        auto uj = qm.front().second;
        qm.pop();
        for(int i=0;i<4;i++){
            if(dist1[ui+dx[i]][uj+dy[i]] != -1){
                if(dist1[ui+dx[i]][uj+dy[i]] > dist1[ui][uj] + 1){
                    dist1[ui+dx[i]][uj+dy[i]] = dist1[ui][uj] + 1;
                    qm.push({ui+dx[i], uj+dy[i]});
                }
            }
        }
    }
    
    //bfs A
    while(!qa.empty()){
        auto ui = qa.front().first;
        auto uj = qa.front().second;
        qa.pop();
        for(int i=0;i<4;i++){
            if(dist2[ui+dx[i]][uj+dy[i]] != -1){
                if((dist1[ui+dx[i]][uj+dy[i]] > (dist2[ui][uj] + 1)) && (dist2[ui+dx[i]][uj+dy[i]] > (dist2[ui][uj] + 1))){
                    dist2[ui+dx[i]][uj+dy[i]] = dist2[ui][uj] + 1;
                    p[ui+dx[i]][uj+dy[i]] = i;
                    qa.push({ui+dx[i], uj+dy[i]});
                }
            }
        }
    }
    
    pair<int,int> ans = {-1, -1};
    for(int i=1;i<=n;i++){
        if(ans != make_pair(-1, -1)) break;
        if(dist2[i][1] != -1 && dist2[i][1] < INF_INT) ans = {i, 1};
        if(dist2[i][m] != -1 && dist2[i][m] < INF_INT) ans = {i, m};
    }
    for(int i=1;i<=m;i++){
        if(ans != make_pair(-1, -1)) break;  
        if(dist2[1][i] != -1 && dist2[1][i] < INF_INT) ans = {1, i};
        if(dist2[n][i] != -1 && dist2[n][i] < INF_INT) ans = {n, i};
    }


    if(ans == make_pair(-1, -1)){
        cout << "NO";
    }else{
        string anspath;
        while(ans != posa){
            int i = p[ans.first][ans.second];
            anspath += cmr[i];
            ans.first -= dx[i];
            ans.second -= dy[i];
        }
        reverse(anspath.begin(), anspath.end());
        cout << "YES\n" << anspath.size() << "\n" << anspath;
    }
    
}
