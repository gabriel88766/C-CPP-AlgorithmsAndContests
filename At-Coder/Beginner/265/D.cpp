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
    ll p, q, r;
    cin >> n >> p >> q >> r;
    vector<ll> ps(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        ps[i] = x + ps[i-1];
    }
    map<ll, bool> mp;
    for(int i=0;i<=n;i++){
        mp[ps[i]] = true;
    }
    bool ok = false;
    for(int i=0;i<=n;i++){
        ll c1 = ps[i] + p;
        ll c2 = ps[i] + p + q;
        ll c3 = ps[i] + p + q + r;
        if(mp.count(c1) && mp.count(c2) && mp.count(c3)) ok = true;

    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
