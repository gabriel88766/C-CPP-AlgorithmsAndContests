#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char grid[52][52];
int dx[] = {1, -1, 1, 0, -1, 1, 0, -1};
int dy[] = {0,0,1,1,1,-1,-1,-1};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int H, W;
    cin >> H >> W;
    for(int i=1;i<=H;i++) for(int j=1;j<=W;j++){
        cin >> grid[i][j];
        if(grid[i][j] == '.') grid[i][j] = '0';
    }
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(grid[i][j] == '#') continue;
            for(int k=0;k<8;k++){
                if(grid[i+dx[k]][j+dy[k]] == '#') grid[i][j]++;
            }
        }
    }
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cout << grid[i][j];
        }
        cout << "\n";
    }
}
