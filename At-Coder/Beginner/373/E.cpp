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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll, ll>> a(n+1);
    vector<ll> ans(n+1);
    ll s = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i].first;
        a[i].second = i;
        s += a[i].first;
    }
    if(m == n){
        for(int i=1;i<=n;i++) cout << "0 ";
        cout << "\n";
        return 0;
    }
    ll mss = k - s;
    sort(a.begin(), a.end());
    vector<ll> ps(n+1);
    for(int i=1;i<=n;i++){
        ps[i] = ps[i-1] + a[i].first;
    }

    //m = 1;
    //i >= n - m + 1, then n-m, otherwise n-m+1
    for(int i=1;i<=n;i++){
        ll lo = 0, hi = mss+1;
        ll li = (i >= n-m+1 ? n-m : n-m+1);
        while(lo != hi){
            ll mid = lo + (hi - lo )/2;
            ll vali = a[i].first + mid;
            ll ind = prev(lower_bound(a.begin(), a.end(), make_pair(vali+1, 0LL))) - a.begin();
            ll qt = 0;
            if(ind >= li){
                qt = (ind - li + 1) * (vali+1) - (ps[ind] - ps[li-1]);
                if(i >= n-m+1) qt += a[i].first - (vali+1);
            }

            // cout << mid << " " << qt << "\n";
            if(mid + qt <= mss) lo = mid+1; //this is lose
            else hi = mid;
            
        }
        if(lo > mss) ans[a[i].second] = -1;
        else ans[a[i].second] = lo;
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

}
