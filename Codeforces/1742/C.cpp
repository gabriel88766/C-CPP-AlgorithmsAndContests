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
        char grid[8][8];
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin >> grid[i][j];
            }
        }
        bool okR = false;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(grid[i][j] != 'R') break;
                if(j == 7) okR = true;
            }
        }
        if(okR) cout <<"R\n";
        else cout << "B\n";
    }
}
