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
    int q;
    cin >> q;
    while(q--){
        int n, m;
        cin >> n >> m;
        vector<vector<char>> v(n+1, vector<char>(m+1));
        vector<int> cntr(n+1), cntc(m+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> v[i][j];
                if(v[i][j] == '.'){
                    cntr[i]++;
                    cntc[j]++;
                }
            }
        }
        int ans = INF_INT;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int c = (v[i][j] == '.') ? 1 : 0;
                ans = min(ans, cntr[i] + cntc[j] - c);
            }
        }
        cout << ans << "\n";
    }
}
