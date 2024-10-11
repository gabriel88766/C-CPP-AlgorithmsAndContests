#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll cnt[9];
bool dp[300];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll w;
    cin >> w;
    ll qnt = 0;
    for(int i=1;i<=8;i++){
        cin >> cnt[i];
        ll mxc = max(0LL, cnt[i] - 8);
        ll rqn = (w-qnt-100)/i;
        rqn = max(rqn, 0LL);
        mxc = min(rqn, mxc);
        qnt += mxc * i;
        cnt[i] -= mxc;
    }
    if(w - qnt >= 288){
        for(int i=1;i<=8;i++){
            qnt += cnt[i] * i;
            assert(cnt[i] <= 8);
        }
        cout << qnt << "\n";
    }else{
        //then make a dp ...
        ll dif = w - qnt;
        dp[0] = true;
        for(int i=1;i<=8;i++){
            for(int j=1;j<=min(cnt[i], dif);j++){
                for(int w = dif;w>=i;w--){
                    dp[w] |= dp[w-i];
                }
            }
        }
        ll ans = qnt;
        for(int wc=0;wc<=dif;wc++){
            if(dp[wc]){
                ans = qnt + wc;
            }
        }
        cout << ans << "\n";
    }
}
