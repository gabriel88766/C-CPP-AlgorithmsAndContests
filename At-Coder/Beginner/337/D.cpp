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
    vector<vector<char>> gr(h, vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> gr[i][j];
        }
    }
    int ans = INF_INT;
    for(int i=0;i<h;i++){
        int c1 = 0, c2 = 0, c3 = 0;
        for(int j=0;j<w;j++){
            if(gr[i][j] == '.') c2++;
            else if(gr[i][j] == 'o') c3++;
            else if(gr[i][j] == 'x') c1++;
            if(c1 + c2 + c3 > k){
                if(gr[i][j-k] == '.') c2--;
                else if(gr[i][j-k] == 'o') c3--;
                else if(gr[i][j-k] == 'x') c1--;
            }
            if(c1 == 0 && c1 + c2 + c3 >= k) ans = min(ans, c2);
        }
    }
    for(int j=0;j<w;j++){
        int c1 = 0, c2 = 0, c3 = 0;
        for(int i=0;i<h;i++){
            if(gr[i][j] == '.') c2++;
            else if(gr[i][j] == 'o') c3++;
            else if(gr[i][j] == 'x') c1++;
            if(c1 + c2 + c3 > k){
                if(gr[i-k][j] == '.') c2--;
                else if(gr[i-k][j] == 'o') c3--;
                else if(gr[i-k][j] == 'x') c1--;
            }
            if(c1 == 0 && c1 + c2 + c3 >= k) ans = min(ans, c2);
        }
    }



    if(ans == INF_INT) cout << "-1\n";
    else cout << ans << "\n";
}
