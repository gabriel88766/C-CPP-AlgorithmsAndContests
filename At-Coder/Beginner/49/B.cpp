#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char mat[102][102];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int H,W;
    cin >> H >> W;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> mat[i][j];
        }
    }
    for(int i=1;i<=(2*H);i++){
        for(int j=1;j<=W;j++){
            cout << mat[(i+1)/2][j];
        }
        cout << "\n";
    }
}
