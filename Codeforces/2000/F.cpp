#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[105][105][105]; //ai, bi, with k points
void init(){
    for(int a=1;a<=100;a++){
        for(int b=1;b<=100;b++){
            for(int k=1;k<=100;k++) dp[a][b][k] = INF_INT;
            for(int k=1;k<=min(100, a+b);k++){
                for(int u=max(k-b, 0);u<=min(a, k);u++){ //u rows selected
                    int v = k - u; //v cols selected
                    dp[a][b][k] = min(dp[a][b][k], u*b + v*a - u * v);
                }
            }
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> dpx(k+1, INF_INT);
        dpx[0] = 0;
        for(int i=0;i<n;i++){
            int a, b;
            cin >> a >> b;
            for(int j=k;j>=1;j--){
                for(int p=1;p<=j;p++){
                    dpx[j] = min(dpx[j], dpx[j-p] + dp[a][b][p]);
                }
            }
        }
        if(dpx[k] != INF_INT) cout << dpx[k] << "\n";
        else cout << "-1\n";
    }
}
