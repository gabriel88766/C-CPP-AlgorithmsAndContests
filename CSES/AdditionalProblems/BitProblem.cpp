#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1 << 20;
const int M = 21;
int dp[N][M], dp2[N][M];
int cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
         cin >> v[i];
         cnt[v[i]]++;
    }
    int msk = (1 << 20) - 1;
    for(int i=1;i<N;i++){//SOS(msk, x). SOS("1001001", 4) = #("1000000") + #("1000001") + #("1001000") + #("1001001")
        dp[i][0] = cnt[i];//SOS(msk, 0) = #(msk);
        for(int j=1;j<M;j++){
            int b = 1 << (j-1);
            dp[i][j] += dp[i][j-1];
            if(i & b) dp[i][j] += dp[i-b][j-1];
        }
    }//first problem solved, cout << dp[v[i]][M-1], quantity of y,  x | y = x, (y is submask)
    //second problem, x is submsk of y
    //third problem x and y arent disjoint (which means y isnt submsk of msk^x, also solved) cout << n-dp[msk^v[i]][M-1]
    for(int i=N-1;i>=1;i--){
        dp2[i][0] = cnt[i];
        for(int j=1;j<M;j++){
            int b = 1 << (j-1);
            dp2[i][j] += dp2[i][j-1];
            if(!(i & b)) dp2[i][j] += dp2[i+b][j-1];
        }
    }
    for(int i=0;i<n;i++){
        cout << dp[v[i]][M-1] << " " << dp2[v[i]][M-1] << " " << n-dp[msk^v[i]][M-1] << "\n";
    }
}
