#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


vector<ll> seq(ll n){
    vector<ll> ans;
    if(__builtin_popcountll(n) == 1){
        ans.push_back(0);
        ans.push_back(n);
        return ans; 
    }
    ll msb = 1LL << (63-__builtin_clzll(n));
    assert((msb & n ) == msb);
    ans.push_back(n^msb);
    auto aux = seq(n^msb);
    for(auto x : aux){
        ans.push_back(msb^x);
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        auto ans = seq(n);
        assert(ans.size());
        if(ans[0] == 0) ans.erase(ans.begin());
        cout << ans.size() << "\n";
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
