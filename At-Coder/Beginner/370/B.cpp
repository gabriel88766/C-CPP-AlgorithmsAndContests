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
    vector<vector<int>> v(n+1, vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){ //j <= i
            cin >> v[i][j];
        }
    }
    int cur = 1;
    for(int j=1;j<=n;j++){
        if(cur >= j) cur = v[cur][j];
        else cur = v[j][cur];
    }
    cout << cur << "\n";
}
