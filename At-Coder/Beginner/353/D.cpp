#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll sum[11], cnt[11], pt[11];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> v(n+1);
    pt[0] = 1;
    for(int i=1;i<=10;i++){
        pt[i] = pt[i-1] * 10;
        pt[i] %= MOD;
    }
    for(int i=1;i<=n;i++){
        cin >> v[i];
        int sz = to_string(v[i]).size();
        sum[sz] = (sum[sz] + v[i]) % MOD;
        cnt[sz]++;
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        int sz = to_string(v[i]).size();
        sum[sz] = (sum[sz] - v[i] + MOD) % MOD;
        cnt[sz]--;
        for(int j=1;j<=10;j++){
            ans = (ans + sum[j]) % MOD;
            ans = (ans + ((v[i] * cnt[j]) % MOD) * pt[j]) % MOD;
        }
    }
    cout << ans << "\n";
}
