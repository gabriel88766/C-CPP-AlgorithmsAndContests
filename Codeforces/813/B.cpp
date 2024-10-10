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
    ll x, y, l, r;
    cin >> x >> y >> l >> r;
    vector<ll> vx = {1}, vy = {1};
    while(r/x >= vx.back()) vx.push_back(vx.back() * x);
    while(r/y >= vy.back()) vy.push_back(vy.back() * y);
    set<pair<ll, ll>> s; //set of intervals
    s.insert({l, r});
    for(auto xx : vx){
        for(auto yy : vy){
            if(xx+yy >= l && xx+yy <= r){
                ll num = xx + yy;
                auto it = s.lower_bound({num, INF_LL});
                if(it != s.begin()){
                    it = prev(it);
                    auto [a, b] = *it;
                    if(b >= num){
                        assert(a <= num);
                        s.erase(it);
                        if(a < num) s.insert({a, num-1});
                        if(b > num) s.insert({num+1, b});
                    }
                }
            }
        }
    }
    if(s.size()){
        ll mx = 0;
        for(auto [l, r] : s){
            mx = max(mx, r - l + 1);
        }
        cout << mx << "\n";
    }else cout << "0\n";
}
