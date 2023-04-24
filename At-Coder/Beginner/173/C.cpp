#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> grid(h, vector<char> (w));
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin >> grid[i][j];
    int ans = 0;
    for(int i=0;i< (1 << h);i++){
        for(int j=0;j < (1 << w);j++){
            int cnt = 0;
            for(int u=0;u<h;u++){
                if(1 << u & i) continue;
                for(int v=0;v<w;v++){
                    if(1 << v & j) continue;
                    if(grid[u][v] == '#') cnt++;
                }
            }
            if(cnt == k) ans++;
        }
    }
    cout << ans;
}
