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
    vector<string> vs(n+1);
    int m = 0;
    for(int i=1;i<=n;i++){
        cin >> vs[i];
        m = max(m, (int)vs[i].size());
    }
    vector<vector<char>> ans(m, vector<char>(n+1));
    for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++){
            int jr = n - j + 1;
            if(vs[jr].size() > i) ans[i][j] = vs[jr][i];
            else ans[i][j] = '*';
        }
        for(int j=n;j>=1;j--){
            if(ans[i][j] == '*') ans[i][j] = '.';
            else break;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++){
            if(ans[i][j] != '.') cout << ans[i][j];
        }
        cout << "\n";
    }

}
