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
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n), c(n);
    for(int i=0;i<n;i++) cin >> a[i] >> b[i] >> c[i];
    ll ans = 0;
    for(int i=0;i<8;i++){
        vector<ll> sum;
        for(int j = 0; j < n; j++){
            ll cur = 0;
            if(i & 1) cur += a[j];
            else cur -= a[j];
            if(i & 2) cur += b[j];
            else cur -= b[j];
            if(i & 4) cur += c[j];
            else cur -= c[j];
            sum.push_back(cur);
        }
        sort(sum.begin(), sum.end(), greater<ll>());
        ll curs = 0;
        for(int j=0;j<m;j++) curs += sum[j];
        ans = max(curs, ans);
    }
    cout << ans << "\n";
}
