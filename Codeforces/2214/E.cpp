#include <bits/stdc++.h>
const int INF_INT = 0x3f3f3f3f;

using namespace std;

int dist[105][105];
int main(){
    int N, m; 
    cin >> N >> m;
    memset(dist, 63, sizeof(dist));
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = c;
    }
    for (int i = 1; i <= 1; i++)
        for (int k = 1; k <= N; k++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    for(int i=2;i<=N;i++){
        if(dist[1][i] == INF_INT) cout << "-1\n";
        else cout << dist[1][i] << "\n";
    }

}