#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


ll bst[301];

ll dp[90301];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in2", "r", stdin); //test input
    ll n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        ll a, b;
        cin >> a >> b;
        bst[a] = max(bst[a], b);
    }
    for(int i=1;i<=90301;i++){
        dp[i] = i;
        for(int j=1;j<=300;j++){
            if(i >= j){
                dp[i] = max(dp[i], dp[i-j + bst[j]] + j);
            }
        }
    }
    if(n <= 90301) cout << dp[n] << "\n";
    else{
        ll ans = 0;
        for(int i=1;i<=300;i++){
            if(bst[i]){
                ll cn = n;
                ll act = (cn - 90301) / (i - bst[i]);
                while(cn - (act + 1) * (i - bst[i]) >= 90000) act++;
                ll cur = act * i;
                
                cn -= act * (i - bst[i]);
                cur += dp[cn];
                ans = max(ans, cur);
            }
        }
        cout << ans << "\n";
    }
}
