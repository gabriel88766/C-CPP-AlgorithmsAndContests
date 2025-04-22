#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
ll mul(ll a, ll b){
    if(a == 0) return 0;
    if(INF_LL/a >= b) return a*b;
    else return INF_LL;
}
ll add(ll a, ll b){
    return min(a + b, INF_LL); 
}

ll sum(ll a, ll n, ll r){
    ll ans = mul(add(a, add(a, mul(n-1, r))), n);
    ans /= 2;
    return ans; 
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    ll h;
    cin >> n >> h;
    vector<pair<ll, ll>> vp(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].second >> vp[i].first;
    }
    sort(vp.begin(), vp.end(), greater<pair<ll, ll>>());
    vector<pair<ll, ll>> vf;
    for(auto &[a, b] : vp){
        if(vf.size() == 0) vf.push_back({a, b}); //d, t
        else{
            if(vf.back().first * vf.back().second < a*b) vf.push_back({a, b});
        }
    }
    // for(auto &[a, b] :  vf) cout << a << " - " << b << "\n";
    ll lo = 1, hi = h;
    while(lo != hi){
        ll mid = lo + (hi - lo)/2;
        ll d = 1;
        ll tt = 0;
        for(int i=0;i<vf.size();i++){
            if(d > mid) break;
            auto &[a, b] = vf[i];
            ll ld;
            if(i + 1 < vf.size()){
                auto &[e, f] = vf[i+1];
                assert(e < a);
                assert(e*f > a*b);
                ll fd = (a*b + e - 1) / e;//fd * e > a * b, fd = (a*b + e - 1) / e;
                assert(fd <= f);
                // fd = min(fd, f);
                if(fd > mid) ld = mid;
                else ld = fd - 1;
            }else{
                ld = mid;
            }
            assert(ld >= d);
            if(d >= b){
                tt = add(tt, mul(ld - d + 1, a*b));
            }else if(ld > b){
                tt = add(tt, mul(ld - b, a*b));
                //a*d + a*(d+1) + ... + a*b;
                tt = add(tt, sum(a*d, b-d+1, a));
            }else{
                //b >= ld
                //a*d + a*(d+1) + ... + a * ld;
                tt = add(tt, sum(a*d, ld-d+1, a));
            }
            d = ld + 1;
        }
        if(tt >= h) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";

}
