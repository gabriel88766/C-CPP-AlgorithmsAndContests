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
    vector<string> ans(n, string(n, '.'));
    string xx = "#.";
    for(int i=0;;i++){
        int j = n - i - 1;
        if(j >= i){
            for(int k=i;k<=j;k++){
                ans[i][k] = ans[j][k] = ans[k][i] = ans[k][j] = xx[i%2];
            }
        }else break;
    }
    for(int i=0;i<n;i++) cout << ans[i] << "\n";
}
