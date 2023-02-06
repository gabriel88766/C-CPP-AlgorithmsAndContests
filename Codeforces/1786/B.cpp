#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll t;
    cin >> t;
    while(t--){
        ll n,w,h;
        cin >> n >> w >> h;
        vector<ll> a(n), b(n);
        ll l = -1e10, r = 1e10;
        bool pos = true;
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i]; 

        for(int i=0;i<n;i++){
            ll nr, nl;
            nr = b[i] - h + w - a[i];
            nl = b[i] + h - w - a[i];
            l = max(l, nl);
            r = min(r, nr);
        }
        if(r >= l) cout << "YES\n";
        else cout << "NO\n";
    }
}
