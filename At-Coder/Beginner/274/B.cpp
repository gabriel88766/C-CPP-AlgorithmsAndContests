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
    //freo      pen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;
    vector<vector<char>> gr(h, vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> gr[i][j];
        }
    }
    for(int j=0;j<w;j++){
        int tt = 0;
        for(int i=0;i<h;i++){
            if(gr[i][j] == '#') tt++;
        }
        cout << tt << " ";
    }
    cout << "\n";
}
