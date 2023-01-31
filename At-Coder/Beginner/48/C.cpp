#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[100005][2];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n), l0(n), l1(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(i != 0){
            //first case, minimize by i-1
            l0[i] = min(x, v[i]);
            dp[i][0] = min(dp[i-1][0] + max(l0[i-1] + v[i] - x,0LL), dp[i-1][1] + max(l1[i-1] + v[i] - x,0LL));
            //minimize by i
            ll aux;
            aux = max(0LL, x-l0[i-1]);
            dp[i][1] = dp[i-1][0] + max(l0[i-1] - x + v[i], 0LL);
            if(dp[i][1] < (dp[i-1][1] + max(l1[i-1] -x + v[i],0LL))){
                l1[i] = aux;
            }else{
                l1[i] = max(0LL, x-l1[i-1]);
                dp[i][1] = dp[i-1][1] + max(l1[i-1] -x + v[i],0LL);
            }
        }else{ 
            dp[i][0] = 0;
            dp[i][1] = 0;
            l0[i] = l1[i] = v[i];
        }
    }
    cout << min(dp[n-1][0], dp[n-1][1]);
}
