#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll pownaive(ll n, ll p){
    ll ans = 1;
    for(int i=0;i<p;i++){
        if(INF_LL/ans >= n) ans *= n;
        else ans = INF_LL;
    }
    return ans;
}

ll mysqrt(ll n){
    ll ans = 0;
    for(ll jmp = 1e9; jmp >= 1; jmp >>= 1){
        while((ans+jmp) * (ans+jmp) <= n) ans += jmp;
    }
    return ans;
}

map<ll, ll> ans;
const ll maxll = 1e18;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> q;
    vector<pair<ll, ll>> qr;
    vector<ll> v;
    vector<ll> nums;
    for(int i=0;i<q;i++){
        ll l, r;
        cin >> l >> r;
        v.push_back(l-1);
        v.push_back(r);
        qr.push_back({l-1, r});
    }
    for(int i=3;i<=60;i++){
        for(int j=1;;j++){
            ll x = pownaive(j, i);
            if(x <= maxll) nums.push_back(x);
            else break;
        }
    }
    sort(nums.begin(), nums.end());
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    int p = 0;
    ll tt = 0;
    for(auto x : v){
        while(p < nums.size() && nums[p] <= x){
            auto sqt = mysqrt(nums[p]);
            if(sqt*sqt != nums[p]) tt++;
            p++;
        }
        ans[x] = mysqrt(x) + tt;
    }
    for(int i=0;i<q;i++){
        auto [x, y] = qr[i];
        cout << ans[y] - ans[x] << "\n";
    }

}
