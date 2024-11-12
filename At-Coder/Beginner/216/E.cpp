#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll sum(ll a, ll b){ //a + a+1 + ... + b
    return ((a + b) * (b-a+1))/2;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    vector<ll> a(n+1);
    ll s = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        s += a[i];
    }
    if(s <= k){
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ans += sum(1, a[i]);
        }
        cout << ans << "\n";
    }else{
        ll lo = 1, hi = 2'000'000'002;
        while(lo != hi){
            ll mid = lo + (hi - lo + 1)/2;
            ll cur = 0;
            for(int i=1;i<=n;i++){
                if(a[i] >= mid) cur += a[i] - mid + 1;
            }
            if(cur >= k) lo = mid;
            else hi = mid - 1;
        }
        ll ans = 0;
        ll aux = 0;
        for(int i=1;i<=n;i++){
            if(a[i] > lo){
                aux += a[i] - lo;
                ans += sum(lo+1, a[i]);
            }
        }
        ans += (k - aux) * lo;
        cout << ans << "\n";
    }
    
}
