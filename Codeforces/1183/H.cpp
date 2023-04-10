#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[105][105];

void calc(string s){
    int n = s.size();
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        int c = s[i-1]-'a';
        for(int j=i-1;j>=0;j--){
            for(int k=0;k<=j;k++){
                dp[i][k+1] += dp[j][k];
                dp[i][k+1] = min(dp[i][k+1], 100000000000000LL);
            }
            if(j && s[i-1] == s[j-1]) break; 
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, k;
    string s;
    cin >> n >> k >> s;
    ll cnt = 0;
    ll ans = 0;
    bool ok = false;
    calc(s);
    for(ll i=n;i>=0;i--){
        ll x = 0;
        for(int j=i;j<=n;j++) x += dp[j][i];
        if(x+cnt >= k){
            ans += (k-cnt)*(n-i);
            ok = true;
            break;
        }else{
            cnt += x;
            ans += x*(n-i);
        }
    }
    if(ok) cout << ans;
    else cout << -1;
}
