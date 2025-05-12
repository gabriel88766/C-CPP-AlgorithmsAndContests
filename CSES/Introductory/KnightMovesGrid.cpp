#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
int dist[N][N];
int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
int dy[] = {2, 2, -2, -2, 1, 1, -1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dist, 63, sizeof(dist));
    int n;
    cin >> n;
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    while(!q.empty()){
        auto [a, b] = q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int xd = a + dx[i];
            int yd = b + dy[i];
            if(xd >= 0 && xd < n && yd >= 0 && yd < n && dist[xd][yd] > dist[a][b] + 1){
                dist[xd][yd] = dist[a][b] + 1;
                q.push({xd, yd});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
