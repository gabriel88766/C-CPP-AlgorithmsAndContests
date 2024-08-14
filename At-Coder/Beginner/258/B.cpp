#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int d=0;d<8;d++){
                string cn = "";
                cn += v[i][j];
                int x = i, y = j;
                for(int z = 1;z<n;z++){
                    x += dx[d];
                    y += dy[d];
                    if(x < 0) x += n;
                    if(x >= n) x -= n;
                    if(y < 0) y += n;
                    if(y >= n) y -= n;
                    cn += v[x][y];
                }
                ans = max(ans, stoll(cn));
            }
        }
    }
    cout << ans << "\n";
    
}
