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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    if(v[0][m-1] || v[0][0] || v[n-1][0] || v[n-1][m-1]){
        cout << "1\n";
    }else{
        bool ok = false;
        for(int j=0;j<m;j++) if(v[0][j] || v[n-1][j]) ok = true;
        for(int i=0;i<n;i++) if(v[i][0] || v[i][m-1]) ok = true;
        if(ok) cout << "2\n";
        else cout << "4\n";
    }
}
