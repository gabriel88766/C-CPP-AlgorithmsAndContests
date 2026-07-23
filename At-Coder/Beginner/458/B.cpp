#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            int ans = 0;
            for(int k=0;k<4;k++){
                int cx = i + dx[k];
                int cy = j + dy[k];
                if(cx >= 1 && cx <= h && cy >= 1 && cy <= w) ans++;
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
