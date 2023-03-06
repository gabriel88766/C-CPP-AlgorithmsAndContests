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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> img(n+2, vector<char>(m+2));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> img[i][j];
    for(int i=0;i<=(n+1);i++) img[i][0] = img[i][m+1] = '#';
    for(int i=0;i<=(m+1);i++) img[0][i] = img[n+1][i] = '#';
    for(int i=0;i<=(n+1);i++) {for(int j=0;j<=(m+1);j++) cout << img[i][j]; cout << "\n";}

}
