#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//DR, DL, UR, UL
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, x, y, p1, p2;
        int dir;
        cin >> n >> m >> x >> y >> p1 >> p2;
        string mv;
        cin >> mv;
        if(mv == "DL") dir = 1;
        else if(mv == "DR") dir = 0;
        else if(mv == "UR") dir = 2;
        else dir = 3;
        int cnt = 0;
        bool ok = false;
        for(int i=0;i<(4*m*n);i++){
            if(x == p1 && y == p2){
                ok = true;
                break;
            }
            x += dx[dir], y += dy[dir];
            if(x <= 0 || x > n || y <= 0 || y > m){
                cnt++;
                int ndir = dir;
                if(x <= 0) ndir -= 2;
                if(x > n) ndir += 2;
                if(y <= 0) ndir -= 1;
                if(y > m) ndir += 1;
                x -= dx[dir], y -= dy[dir];
                dir = ndir;
            }
        }
        if(ok) cout << cnt << "\n";
        else cout << "-1\n";
    }
}
