#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dist[102][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dist, 63, sizeof(dist));
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    dist[a][0] = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, a, 0});
    dist[0][0] = dist[0][1] = dist[101][0] = dist[101][1] = -1;
    while(pq.size()){
        auto [d, u, j] = pq.top();
        pq.pop();
        if(d > dist[u][j]) continue;
        if(j == 0){ //from a down
            if(dist[u-1][1] > dist[u][0] + x){
                dist[u-1][1] = dist[u][0] + x;
                pq.push({dist[u-1][1], u-1, 1});
            }
        }
        if(j == 1){ //from b up
            if(dist[u+1][0] > dist[u][1] + x){
                dist[u+1][0] = dist[u][1] + x;
                pq.push({dist[u+1][0], u+1, 0});
            }
        }
        if(dist[u][j^1] > dist[u][j] + x){ //same floor
            dist[u][j^1] = dist[u][j] + x;
            pq.push({dist[u][j^1], u, j^1});
        }
        if(dist[u+1][j] > dist[u][j] + y){
            dist[u+1][j] = dist[u][j] + y;
            pq.push({dist[u+1][j], u+1, j});
        }
        if(dist[u-1][j] > dist[u][j] + y){
            dist[u-1][j] = dist[u][j] + y;
            pq.push({dist[u-1][j], u-1, j});
        }
    }
    cout << dist[b][1] << "\n";
}
