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
    int n;
    ll k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll x = *max_element(v.begin(), v.end());
    ll ans;
    for(ll i = 1; i <= 200'000; i++){
        //hardcoded, f!#@ yeah!
        ll cur = 0;
        for(int j=0;j<n;j++){
            ll r = v[j] % i;
            if(r != 0) cur += i - r;
        }
        if(cur <= k) ans = i;
    }
    //now what if d >= 200'001?
    ll cd = 200'001;
    while(cd < INF_LL){
        ll mc = INF_LL - 1;
        for(int j=0;j<n;j++){
            int cur = v[j] / cd;
            if(cur != 0){
                ll val = v[j] / (v[j] / cd);
                mc = min(mc, val);
            }
        }
        ll cur = 0;
        for(int j=0;j<n;j++){
            ll r = v[j] % mc;
            if(r != 0) cur += mc - r;
            if(cur > INF_LL) break;
        }
        if(cur <= k) ans = mc;
        else{
            ll ms = mc - cd;
            ll cs = 0;
            cur = 0;
            for(int j=0;j<n;j++){
                ll r = v[j] % cd;
                if(r != 0) cur += cd - r;
                if(cur > INF_LL) break;
                cs += 1 + v[j] / cd;
            }
            if(cur <= k){
                ans = cd + (k - cur) / cs;
            }
        }

        cd = mc + 1;
    }


    cout << ans << "\n";
}   
