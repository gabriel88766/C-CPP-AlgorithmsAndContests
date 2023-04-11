#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


vector<ll> allDivs(ll n){
    vector<ll> divs;
    for(ll i=1;i*i<=n;i++){
        if(!(n%i)){
            divs.push_back(i);
            if(i*i != n) divs.push_back(n/i);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    if(a < b) swap(a,b);
    if(a == b){
        a = 0, b = 0;
        ans++;
    }
    while(b >= 1){ // a is greater than b
        auto x = allDivs(max(a,b)-min(a,b));
        ll g = __gcd(a, b);
        ll maxnum = 0;
        for(auto y : x){
            if(y <= g) continue;
            ll cur = (b/y)*y;
            if(!((b-cur)%g)) maxnum = max(maxnum, cur);
        }
        ll diff = b-maxnum;
        a-=diff, b-=diff;
        ans += diff/g;
    }
    cout << ans;
}
