#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool is_square(ll x){
    if(x < 0) return false;
    if(x == 0) return true;
    ll y = sqrt(x);
    while(y*y < x) y++;
    while((y-1)*(y-1) >= x) y--;
    return y*y == x;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll x;
    cin >> x;
    vector<ll> ans;
    // ll px = 20'000'000;
    for(ll i=-10'000'000; i<=10'000'000; i++){
        ll cur = i*i + i + x; //at most 2*10^14 - 10^7
        if(is_square(cur)){
            ans.push_back(i);
        }
    }
    assert(ans.size() <= 10'000'000); //never assert
    //now need to find n > 10'000'000 or n < -10'000'000
    for(ll i=-10'000'000;i<=10'000'000;i++){
        // n² + n + x = (n + i)²
        ll v1 = x - i*i; // from -2*10^14 to 2*10^14
        ll v2 = 2*i - 1; //abs of this is at least 1
        ll x = v1/v2; //this must be at most 2*10^14
        if(v1 % v2 == 0 && llabs(x) > 10'000'000) ans.push_back(x);
    }
    assert(ans.size() <= 10'000'000); //never assert
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << "\n";
    for(auto x : ans ) cout << x << " ";
    cout << "\n";
}
