#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[10001];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    for(int i=0;i<k;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        for(auto x : v){
            if(x <= i){
                dp[i] = max(dp[i], x + (i-x - dp[i-x]));
            }else break;
        }
    }
    cout << dp[n] << "\n";
}
