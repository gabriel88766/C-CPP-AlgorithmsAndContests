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
    vector<pair<ll,ll>> vp;
    for(int i=0;i<n;i++){
        ll l, r;
        cin >> l >> r;
        vp.push_back({l, r});
    }
    ll lo = -2e9, hi = 2e9, mid;
    while(lo != hi){
        mid = lo + (hi - lo) / 2;
        ll cnt = 0;
        for(auto x : vp){
            cnt += max(min(x.second, mid) - x.first + 1, 0LL);
        }
        if(cnt > k) hi = mid;
        else lo = mid + 1;
    }
    cout << lo;
}
