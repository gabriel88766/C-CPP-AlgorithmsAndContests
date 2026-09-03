#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
char vis[1505][1505][4];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    int ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    vector<string> gr(n+2, string(n+2, '#'));
    vector<vector<int>> d(n+2, vector<int>(n+2, INF_INT));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> gr[i][j];
        }
    }
    d[ax][ay] = 0;
    queue<pair<int, int>> q;
    q.push({ax, ay});
    while(q.size()){
        auto [a, b] = q.front();
        q.pop();
        for(int k = 0; k < 4; k++){
            for(int qt = 1; ; qt++){
                int cx = a + dx[k] * qt;
                int cy = b + dy[k] * qt;
                if(gr[cx][cy] == '.' && d[cx][cy] > d[a][b] + 1){
                    d[cx][cy] = d[a][b] + 1;
                    vis[cx][cy][k] = true;
                    q.push({cx, cy});
                }else if(gr[cx][cy] == '.' && d[cx][cy] == d[a][b] + 1 && vis[cx][cy][k] == false){
                    vis[cx][cy][k] = true;
                }else break;
            }
        }
    }
    if(d[bx][by] != INF_INT) cout << d[bx][by] << "\n";
    else cout << "-1\n";
}
