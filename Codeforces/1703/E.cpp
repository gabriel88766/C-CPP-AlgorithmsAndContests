#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        vector<vector<char>> grid(n+1, vector<char> (n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> grid[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int qt0 = 0, qt1 = 0;
                int curi = i, curj = j;
                for(int k=0;k<4;k++){
                    if(grid[curi][curj] == '0') qt0++;
                    else qt1++;
                    //next
                    int aux = curj;
                    curj = curi;
                    curi = n-aux+1;
                }
                ans += min(qt0,qt1);
            }
        }
        cout << ans/4 << "\n";
    }
}
