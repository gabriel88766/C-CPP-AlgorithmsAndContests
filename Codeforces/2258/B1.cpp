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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), cnt(m+1);
        vector<ll> ps(m+1);
        for(int i=0;i<n;i++){
            cin >> a[i];
            cnt[a[i]]++;
        }
        for(int i=1;i<=m;i++){
            ps[i] = ps[i-1] + cnt[i];
        }
        //let k, and x the answer will be sum min(k, a[i]/x) for those a[i] != (k+1)*x, k+1 otherwise
        //if (k+1) * x >= m don't test


        for(ll k=1;k<=1;k++){
            ll ans = 0;
            for(ll x = 1; k*x <= m; x++){
                ll cans = 0;
                if((k+1) * x <= m) cans += (k+1) * cnt[(k+1) * x];
                //optimize this
                for(ll u = 1; u <= k; u++){
                    ll lx = (u + 1) * x - 1;
                    lx = min(lx, m);
                    cans += u * (ps[lx] - ps[u*x-1]);
                }
                if(m > (k+1) * x) cans += k * (ps[m] - ps[(k+1) * x]);
                ans = max(ans, cans);
            }
            cout << ans << "\n";
        }
    }
}
