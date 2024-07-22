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
    int n, q;
    cin >> n >> q;
    vector<ll> v(n), ps(n, 0);
    for(int i=0;i<n;i++){
        cin >> v[i];
        ps[i] = v[i];
        if(i != 0) ps[i] += ps[i-1];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        ll ans = ps[r-1];
        if(l != 0) ans -= ps[l-1];
        cout << ans << "\n";
    }
}
