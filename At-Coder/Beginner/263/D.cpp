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
    int n;
    ll l, r;
    cin >> n >> l >> r;
    vector<ll> v(n), ps(n);
    vector<ll> lf(n), rg(n+1);
    for(int i=0;i<n;i++){
        cin >> v[i];
        ps[i] += v[i];
        if(i != 0) ps[i] += ps[i-1];
        lf[i] = ps[i] - l * (i+1);
    }
    for(int i=n-1;i>=0;i--){
        rg[i] = ps[n-1];
        if(i != 0) rg[i] -= ps[i-1];
        rg[i] -= r * (n-1 - i + 1);
        rg[i] = max(rg[i], rg[i+1]);
        // cout << rg[i] << " ";
    }
    ll ans;
    ans = max(0LL, rg[0]);
    for(int i=0;i<n;i++){
        ans = max(ans, lf[i] + rg[i+1]);
    }
    cout << ps[n-1] - ans << "\n";
    

}
