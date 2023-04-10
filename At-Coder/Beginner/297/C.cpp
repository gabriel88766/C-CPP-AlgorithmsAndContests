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
    int H, W;
    cin >> H >> W;
    vector<vector<char>> v(H, vector<char>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> v[i][j];
        }
    }
    for(int i=0;i<H;i++){
        for(int j=1;j<W;j++){
            if(v[i][j] == 'T' && v[i][j-1] == 'T'){
                v[i][j] = 'C';
                v[i][j-1] = 'P';
            }
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout << v[i][j];
        }
        cout << "\n";
    }
}
