#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
ll dp[N][2]; //[0] min T when F = 0, [1] min F when T = 0
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n+1), b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    bool ok = true;
    memset(dp, 63, sizeof(dp));
    dp[0][0] = dp[0][1] = 0;
    for(int i=1;i<=n;i++){
        //WEIRD!
        for(int s=0;s<2;s++){
            if(dp[i-1][s] > k) continue;
            for(int d=0;d<2;d++){
                if(a[i] > b[i]){
                    if(s == 0 && d == 0){
                        if(a[i] + dp[i-1][s] <= k*b[i]) dp[i][d] = 1;
                        else if(a[i] + dp[i-1][s] <= k * (b[i] + 1)) dp[i][d] = min(dp[i][d], a[i] + dp[i-1][s] - k*b[i]);
                    }
                    if(s == 0 && d == 1){
                        if(a[i] + dp[i-1][s] <= k*b[i]) dp[i][d] = 1;
                    }
                    if(s == 1 && d == 0){
                        if(a[i] <= b[i]*k) dp[i][d] = 1;
                        else if(a[i] <= k*(b[i] + 1)) dp[i][d] = min(dp[i][d], a[i] - b[i]*k);
                    }
                    if(s == 1 && d == 1){
                        if(a[i] <= b[i]*k) dp[i][d] = 1;
                    }
                }else{
                    //b[i] >= a[i]
                    if(s == 0 && d == 0){
                        if(b[i] <= k * a[i]) dp[i][d] = 1;
                    }
                    if(s == 0 && d == 1){
                        if(b[i] <= k * a[i]){
                            if(a[i] == b[i]){
                                if(dp[i-1][s] != k) dp[i][d] = 1;
                                else if(k != 1 && a[i] != 1) dp[i][d] = 1;
                            }else dp[i][d] = 1;
                        }else if(b[i] <= k * (a[i] + 1)) dp[i][d] = min(b[i] - k * a[i], dp[i][d]);
                    }
                    if(s == 1 && d == 0){
                        if(b[i] + dp[i-1][s] <= k*a[i]){
                            if(b[i] == a[i]){
                                if(dp[i-1][s] != k) dp[i][d] = 1;
                                else if(k != 1 && a[i] != 1) dp[i][d] = 1;
                            } else dp[i][d] = 1;
                        } 
                    }
                    if(s == 1 && d == 1){
                        if(b[i] + dp[i-1][s] <= k * a[i]){
                            dp[i][d] = 1;
                        }else if(b[i] + dp[i-1][s] <= k * (a[i] + 1)) dp[i][d] = min(b[i] + dp[i-1][s] - k * a[i], dp[i][d]);
                    }
                }
            }
        }
        if(dp[i][0] > k && dp[i][1] > k){
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
