#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char gr[105][105];
char vis[105][105];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
        }
    }
    vis[x][y] = true;
    string s;
    cin >> s;
    for(auto c : s){
        if(c == 'U' && gr[x-1][y] != '#') x--;
        else if(c == 'D' && gr[x+1][y] != '#') x++;
        else if(c == 'L' && gr[x][y-1] != '#') y--;
        else if(c == 'R' && gr[x][y+1] != '#') y++;
        vis[x][y] = true;
    }
    int ans = 0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(gr[i][j] == '@' && vis[i][j]) ans++;
        }
    }
    cout << x << " " << y << " " << ans << "\n";
}
