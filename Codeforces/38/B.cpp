#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool t[9][9];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int dkx[] = {1,1,-1,-1,2,2,-2,-2};
int dky[] = {2,-2,2,-2,1,-1,1,-1};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n1, n2;
    char c1, c2;
    cin >> c1 >> n1 >> c2 >> n2;
    c1 = c1 - 'a' + 1;
    c2 = c2 - 'a' + 1;
    for(int i=0;i<8;i++){
        for(int j=0;j<4;j++){
            int x = c1 + i*dx[j];
            int y = n1 + i*dy[j];
            if(x <= 8 && x >= 1 && y <= 8 && y >= 1) t[x][y] = true;
        }
        int x2 = c2 + dkx[i];
        int y2 = n2 + dky[i];
        if(x2 <= 8 && x2 >= 1 && y2 <= 8 && y2 >= 1) t[x2][y2] = true;
        x2 = c2 + dkx[i];
        y2 = n2 + dky[i];
        if(x2 <= 8 && x2 >= 1 && y2 <= 8 && y2 >= 1) t[x2][y2] = true;
        x2 = c1 + dkx[i];
        y2 = n1 + dky[i];
        if(x2 <= 8 && x2 >= 1 && y2 <= 8 && y2 >= 1) t[x2][y2] = true;

    }
    t[c2][n2] = true;

    int ans = 0;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            if(!t[i][j]) ans++;
        }
    }
    cout << ans;
}
