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
    int t;
    cin >> t;
    while(t--){
        int h, w;
        cin >> h >> w;
        int ch = h, cw = w;
        if(h % 2 == 0) ch--;
        if(w % 2 == 0) cw--;
        vector<vector<char>> ans(ch, vector<char>(cw, '0'));
        for(int i=0;i<ch;i++){
            for(int j=0;j<cw;j++){
                if(i == 0 || j == 0 || i == ch-1 || j == cw-1){
                    if((i + j) % 2 == 0) ans[i][j] = '1';
                }
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(h == 1 && ch != h) cout << "0";
                else if(w == 1 && cw != w) cout << "0";
                else{
                    int ci = i, cj = j;
                    if(h != ch && ci > 1) ci--;
                    if(w != cw && cj > 1) cj--;
                    // cout << i << " " << j << " " << ci << " " << cj << "\n";
                    cout << ans[ci][cj];
                }
            }
            cout << "\n";
        }
    }
}
