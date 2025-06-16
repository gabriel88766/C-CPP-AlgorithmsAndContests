#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll gsum(ll a, ll b, ll n){
    ll sum = (a + b) * n;
    sum /= 2;
    return sum % MOD;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    vector<int> dv;
    for(int i=1;i*i<=k;i++){
        if(k % i == 0){
            dv.push_back(i);
            if(i*i != k) dv.push_back(k/i);
        }
    }
    sort(dv.begin(), dv.end());
    vector<ll> ansg(dv.size());
    for(int i=0;i<dv.size();i++){
        ll fdiv = 1;
        ll ldiv = (n/dv[i]);
        if(ldiv >= fdiv){
            ll sum = gsum(fdiv, ldiv, ldiv - fdiv + 1);
            sum = (sum * dv[i]) % MOD; 
            ansg[i] = sum;
        }
    }
    // cout << ansg[0] << " " << ansg[1] << "\n";
    for(int i=dv.size() - 1;i>=0;i--){
        for(int j=i+1;j<dv.size();j++){
            if(dv[j] % dv[i] == 0) ansg[i] -= ansg[j];
        }
        // cout << ansg[i] << " ";
        ans = (ans + ansg[i] * (k / dv[i])) % MOD;
    }
    if(ans < 0) ans += MOD;
    cout << ans << "\n";
}
