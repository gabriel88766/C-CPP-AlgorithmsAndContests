#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
ll mat[N][N];
bool vis[N][N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> mat[i][j];
        }
    }
    vector<pair<int, int>> ord;
    int x = 1, y = 1;
    int dx = 1, dy = 0;
    vis[x][y] = true;
    ord.push_back({x, y});
    while(true){
        if(x + dx >= 1 && x + dx <= n && y + dy >= 1 && y + dy <= n && vis[x+dx][y+dy] == false){
            x += dx;
            y += dy;
        }else{
            int nx = -dy;
            int ny = dx;
            dx = nx;
            dy = ny;
            if(x + dx >= 1 && x + dx <= n && y + dy >= 1 && y + dy <= n && vis[x+dx][y+dy] == false){
                x += dx;
                y += dy;
            }else break;
        }
        ord.push_back({x, y});
        vis[x][y] = true;
    }
    ll ans = 0;
    for(int i=0;i<8;i++){
        int b0 = i & 1;
        int b1 = i & 2;
        int b2 = i & 4;
        ll cur = 0;
        for(auto [a, b] : ord){
            int na = a, nb = b;
            if(b0) swap(na, nb);
            if(b1) na = n - na + 1;
            if(b2) nb = n - nb + 1;
            cur += mat[na][nb];
            if(cur < 0) cur = 0;
            ans = max(ans, cur);
        }
    }
    cout << ans << "\n";

}
