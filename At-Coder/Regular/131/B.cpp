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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> gr(h+2, vector<char>(w+2, 'x'));
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(gr[i][j] != '.') continue;
            for(char c = '1'; c<='5';c++){
                if(gr[i+1][j] != c && gr[i-1][j] != c && gr[i][j-1] != c && gr[i][j+1] != c){
                    gr[i][j] = c;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cout << gr[i][j];
        }
        cout << "\n";
    }
}
