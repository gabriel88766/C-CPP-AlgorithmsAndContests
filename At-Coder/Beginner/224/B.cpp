#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int grid[51][51];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int H, W;
    cin >> H >> W;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> grid[i][j];
        }
    }
    bool ok = true;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            for(int u=i+1;u<=H;u++){
                for(int v=j+1;v<=W;v++){
                    if(!((grid[i][j] + grid[u][v]) <= (grid[u][j] + grid[i][v]))) ok = false;
                }
            }
        }
    }
    if(ok) cout << "Yes";
    else cout << "No";
}
