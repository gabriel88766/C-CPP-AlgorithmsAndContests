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
    ll n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    ll qx = 0;
    for(auto x : s){
        if(x == 'x') qx++;
    }
    ll tr = k / qx;
    if(tr == m){
        cout << n*m << "\n";
        return 0;
    }
    ll ans = tr * n;
    k -= qx * tr;
    k += 1;
    ll mx = 0;
    if(tr != m-1) s += s;
    vector<ll> idx {-1};
    for(int j=0;j<s.size();j++){
        if(s[j] == 'x') idx.push_back(j);
    }
    idx.push_back(s.size());
    for(int j=k;j<idx.size();j++) mx = max(mx, idx[j] - idx[j-k]);
    ans += mx - 1;
    cout << ans << "\n";
}
