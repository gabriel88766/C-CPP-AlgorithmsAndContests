#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
int d1[N][N], d2[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, k;
    cin >> h >> w >> k;
    memset(d1, 63, sizeof(d1));
    memset(d2, 63, sizeof(d2));
    queue<pair<int, int>> qp;
    for(int i=0;i<k;i++){
        int r, c;
        cin >> r >> c;
        d1[r][c] = d2[r][c] = 0;
        qp.push({r, c});
    }
    while(qp.size()){
        auto [a, b]  = qp.front();
        qp.pop();
        for(int i=0;i<4;i++){
            int xd = a + dx[i];
            int yd = b + dy[i];
            if(xd >= 1 && xd <= h && yd >= 1 && yd <= w){
                if(d1[xd][yd] == INF_INT) d1[xd][yd] = 1; //the actual distance doesn't matter
                else if(d2[xd][yd] == INF_INT){
                    d2[xd][yd] = d2[a][b] + 1;
                    qp.push({xd, yd});
                }
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(d2[i][j] != INF_INT) ans += d2[i][j];
        }
    }
    cout << ans << "\n";
}
