#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll ncr[31][31];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ncr[0][0] = 1;
    for(int i=1;i<=30;i++){
        ncr[i][0] = 1;
        for(int j=1;j<=i;j++){
            ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
            // cout << ncr[i][j] << " ";
        }
        // cout << "\n";
    }
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int xc = 0;
        for(int i=0;;i++){
            if((1 << i) == n){
                if(i < k) xc++;
                break;
            }
            int mx = i;
            int lim = k - (i + 1);
            for(int j=0;j<=min(lim, mx);j++){
                xc += ncr[mx][j];
            }
        }
        int ans = n - xc;
        cout << ans << "\n";
    }
}
