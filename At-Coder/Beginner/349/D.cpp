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
    ll l, r;
    cin >> l >> r;
    vector<pair<ll, ll>> ans;
    while(l < r){
        if(l == 0){
            ll b = 63-__builtin_clzll(r);
            ans.push_back({0, 1LL << b});
            l = 1LL << b;
        }else{
            ll b = __builtin_ctzll(l);
            ll sb = 1LL << b;
            if(l + sb <= r){
                ans.push_back({l, l + sb});
                l += sb;
            }else{
                ll msk = l ^ r;
                ll b = 63-__builtin_clzll(msk);
                ans.push_back({l, l + (1LL << b)});
                l += 1LL << b;
            }
        }
        
    }
    cout << ans.size() << "\n";
    for(auto [a, b] :ans) cout << a << " " << b << "\n";
}
