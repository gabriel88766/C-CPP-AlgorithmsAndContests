#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 20;
int adj[N];
int dp[1 << N];
int par[1 << N];
bool okm[1 << N];
int ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    // for(int i=0;i<n;i++) adj[i] |= (1 << i);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        // --a, --b;
        adj[a] |= (1 << b);
        adj[b] |= (1 << a);
    }
    memset(dp, 63, sizeof(dp));
    dp[0] = 0;
    for(int i=0;i<(1 << n);i++){
        //check if this mask is ok;
        bool ok = true;
        int msk = 0;
        for(int j=0;j<n;j++){
            if(i & (1 << j)){
                if(msk & (1 << j)) ok = false;
                else msk |= adj[j];
            }
        }
        if(ok) okm[i] = true;
    }
    for(int m=1;m<(1 << n);m++){
        for (int s=m; s; s=(s-1)&m){ 
            if(okm[s]){
                if(dp[m] > dp[m ^ s] + 1){
                    dp[m] = dp[m ^ s] + 1;
                    par[m] = m ^ s;
                }
            }
        }
    }
    int cs = (1 << n) - 1;
    cout << dp[cs] << "\n";
}
