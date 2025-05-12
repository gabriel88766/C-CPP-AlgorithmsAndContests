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
    vector<vector<int>> ans(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vector<bool> fd(2*n+1, false);
            for(int k=0;k<j;k++) fd[ans[i][k]] = true;
            for(int k=0;k<i;k++) fd[ans[k][j]] = true;
            for(int k=0;k<=2*n;k++){
                if(!fd[k]){
                    ans[i][j] = k;
                    break;
                }
            }
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
