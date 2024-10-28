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
    int t;
    cin >> t;
    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        ll ans = 0;
        sort(v.begin(), v.end()); //lol!
        ll cq = 0;
        for(int i=0;i<n;i++){
            ll cur = min(m, k-cq);
            ans += cur * cq;
            ans += cur * v[i];
            cq += cur;
        }
        cout << ans << "\n";
    }
}
