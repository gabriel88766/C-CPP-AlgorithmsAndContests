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
    int n;
    cin >> n;
    vector<vector<char>> gr(n+1, vector<char>(n+1));
    auto ans = gr;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> gr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int layer = min(min(i, n+1-i), min(j, n+1-j));
            layer %= 4;
            int ri = i, rj = j;
            for(int r=1;r<=layer;r++){
                swap(ri, rj);
                rj = n + 1 - rj;
            }
            ans[ri][rj] = gr[i][j];
        }
    }   
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }
    
}
