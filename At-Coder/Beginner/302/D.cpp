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
    int n, m;
    ll d;
    cin >> n >> m >> d;
    vector<ll> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = -1;
    for(int i=0;i<n;i++){
        auto it = lower_bound(b.begin(), b.end(), a[i] + d + 1);
        if(it == b.begin()) continue;
        it = prev(it);
        auto it2 = lower_bound(b.begin(), b.end(), a[i] - d);
        if((it-it2) >= 0){
            ans = max(ans, a[i] + *it);
        }
    }
    cout << ans;
}