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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i =0;i<n;i++) cin >> v[i];
    ll lo = 0, hi = 1e18;
    auto do_act = [&](vector<ll> u, ll tt, int p = 0){
        ll ans = 0;
        ll all = tt / u.size();
        ll lst = tt % u.size();
        for(int i=0;i<u.size();i++){
            ll cur = min(u[i], all + (i <= lst ? 1 : 0));
            u[i] -= cur;
            ans += cur;
        }
        if(p == 1){
            for(auto &x : u) cout << x <<  " ";
            cout << "\n";
        }
        return ans;
    };  
    while(lo != hi){
        ll mid = lo + (hi - lo + 1)/2;
        if(do_act(v, mid) < k) lo = mid;
        else hi = mid - 1;
    }
    if(do_act(v, lo) == k) do_act(v, lo, 1);
    else do_act(v, lo + 1, 1);
}
