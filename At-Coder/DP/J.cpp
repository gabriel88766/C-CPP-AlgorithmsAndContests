#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 303;
double dp[N][N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;


    for(int k=0;k<=n;k++){
        for(int j=0;j<=n;j++){
            for(int i=0;i<=n;i++){
                if(!(i || j || k)) continue;
                long double pa =i, pb = j, pc = k, pd;
                pa /= n, pb /= n, pc /= n;
                pd = pa+pb+pc;
                if(k) dp[k][j][i] += (dp[k-1][j+1][i]+1) * pc;
                if(j) dp[k][j][i] += (dp[k][j-1][i+1]+1) * pb;
                if(i) dp[k][j][i] += (dp[k][j][i-1]+1) * pa;
                dp[k][j][i] += 1-pd;
                dp[k][j][i] /= pd;
            }
        }
    }
    
    int  cnt1 =0, cnt2 = 0, cnt3 = 0;

    for(int i=1;i<=n;i++){
        int inp;
        cin >> inp;
        if(inp == 1) cnt1++;
        if(inp == 2) cnt2++;
        if(inp == 3) cnt3++;
    }
    cout << fixed << setprecision(15) << dp[cnt3][cnt2][cnt1];
}
