#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char board[9][9];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                cin >> board[i][j];
            }
        }
        bool ok = false;
        for(int i=2;i<=7;i++){
            if(ok) break;
            for(int j=2;j<=7;j++){
                if(ok) break;
                if(board[i][j] == '#'){
                    if(board[i+1][j+1] == '#' && board[i-1][j+1] == '#' && board[i-1][j-1] == '#' && board[i+1][j-1] == '#'){
                        cout << i << " " << j << "\n";
                        ok = true;
                    }
                }
            }
        }
    }

}   
