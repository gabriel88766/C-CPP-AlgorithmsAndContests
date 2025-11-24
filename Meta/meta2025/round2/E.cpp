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
    freopen("descending_platforms_input.txt", "r", stdin); //test input
    freopen("out.txt", "w", stdout);
    ll t;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        ll n, m;
        cin >> n >> m;
        vector<ll> vx(n), ps(n+1);
        for(ll j = 0; j < n; j++) cin >> vx[j];
        for(ll j = 1; j <= n; j++) ps[j] = ps[j-1] + vx[j-1];
        vector<ll> dp(n * (n + 1) + 1), par(n * (n + 1) + 1);
        for(ll j = 1; j <= n * (n+1); j++){
            for(ll u = 1; u <= n; u++){
                if(j >= u){
                    if(dp[j - u] + ps[u] > dp[j]){
                        dp[j] = dp[j - u] + ps[u];
                        par[j] = j - u;
                    }
                }
            }
        }
        cout << "Case #" << i << ": ";
        if(dp[n * (n + 1)] >= m){
            ll x;
            for(ll j = 1;j <= (n * (n+1)); j++){
                if(dp[j] >= m){
                    x = j;
                    break;
                }
            }
            cout << x << "\n";
            vector<ll> ans(n+1);
            while(x){
                ll dif = x - par[x];
                ans[dif]++;
                x -= dif;
            }
            for(ll j=n-1;j>=1;j--) ans[j] += ans[j+1];
            for(ll j=1;j<=n;j++) cout << ans[j] << " ";
            cout << "\n";
        }else{
            ll lo = n * (n + 1) + 1, hi = 1e12;
            while(lo != hi){
                ll mid = lo + (hi - lo) / 2;
                ll mx = 0;
                for(ll j = 1; j <= n; j++){
                    ll cn = mid;
                    ll act = (cn - (n * (n+1))) / j;
                    while(cn - (act + 1) * j >= n*n) act++;
                    ll cur;
                    if(INF_LL / act >= ps[j]) cur = act * ps[j];
                    else cur = INF_LL;
                    cur += dp[cn - act * j];
                    mx = max(mx, cur);
                }
                if(mx >= m) hi = mid;
                else lo = mid + 1;
            }
            cout << lo << "\n";
            for(ll j = 1; j <= n; j++){
                ll cn = lo;
                ll act = (cn - (n * (n+1))) / j;
                while(cn - (act + 1) * j >= n*n) act++;
                ll cur;
                if(INF_LL / act >= ps[j]) cur = act * ps[j];
                else cur = INF_LL;
                cur += dp[cn - act * j];
                if(cur >= m){
                    vector<ll> ans(n+1);
                    ans[j] += act;
                    ll x = cn - act * j;
                    while(x){
                        ll dif = x - par[x];
                        ans[dif]++;
                        x -= dif;
                    }
                    for(ll j=n-1;j>=1;j--) ans[j] += ans[j+1];
                    for(ll j=1;j<=n;j++) cout << ans[j] << " ";
                    cout << "\n";
                    break;
                }
            }
        }
    }
}   
