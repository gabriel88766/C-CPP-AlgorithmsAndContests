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
    vector<pair<ll, pair<ll,ll>>> vp;
    ll n, m;
    cin >> m >> n;
    vector<ll> ans(n);
    for(int i=0;i<n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        vp.push_back({a, {b,c}});
    }
    if(m == 0){// JUST, WHY????????????
        cout << "0\n";
        for(int i=0;i<n;i++) cout << 0 << " ";
        return 0;
    }
    ll lo = 1, hi = 3e9+3, mid;

    while(lo != hi){
        mid = (hi+lo)/2;
        ll cntb = 0;
        for(int i=0;i<n;i++){
            ll t = vp[i].first*vp[i].second.first + vp[i].second.second;
            ll cur = (mid/t)*vp[i].second.first + min((mid%t)/vp[i].first, vp[i].second.first);
            cur = min(cur, m - cntb);
            cntb += cur;
        }
        if(cntb == m) hi = mid;
        else lo = mid + 1;
    }

    ll cntb = 0;

    for(int i=0;i<n;i++){
        ll t = vp[i].first*vp[i].second.first + vp[i].second.second;
        ll cur = (lo/t)*vp[i].second.first + min((lo%t)/vp[i].first, vp[i].second.first);
        cur = min(cur, m - cntb);
        cntb += cur;
        ans[i] = cur;
    }

    cout << lo << "\n";
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
}
