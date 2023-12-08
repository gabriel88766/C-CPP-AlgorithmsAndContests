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
    int n, k;
    cin >> n >> k;
    if(n*n < k) cout << "-1\n";
    else{
        vector<vector<int>> ans(n, vector<int>(n));
        if(k % 2) {ans[0][0] = 1; k--;}
        for(int i=0;i<n;i++){
            if(k == 0) break;
            for(int j=0;j<n;j++){
                if(ans[i][j] == 1) continue;
                if(i == j) ans[i][i] = ans[i+1][i+1] = 1;
                else ans[i][j] = ans[j][i] = 1;
                k -= 2;
                if(k == 0) break;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
