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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<char>> ans(2*n, vector<char>(2*n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i+j) % 2){
                    ans[2*i][2*j] = ans[2*i+1][2*j] = ans[2*i][2*j+1] = ans[2*i+1][2*j+1] = '.';
                }else{
                    ans[2*i][2*j] = ans[2*i+1][2*j] = ans[2*i][2*j+1] = ans[2*i+1][2*j+1] = '#';
                }
            }
        }
        for(int i=0;i<2*n;i++){
            for(int j=0;j<2*n;j++){
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }
}
