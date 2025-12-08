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
    ll n, c;
    cin >> n >> c;
    map<ll, ll> mp;
    for(int i=1;i<=n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        mp[a] += c;
        mp[b+1] -= c;
    }
    ll lb = 0, cs = 0;
    ll ans = 0;
    for(auto [k, v] : mp){
        ans += (k - lb) * min(cs, c);
        cs += v;
        lb = k;
    }
    cout << ans << "\n";

}   
