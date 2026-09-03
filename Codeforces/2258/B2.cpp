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
        ll s = 0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            s += a[i];
            cnt[a[i]]++;
        }
        for(int i=1;i<=m;i++){
            ps[i] = ps[i-1] + cnt[i];
        }
        //This was wrong!!
        //let k, and x the answer will be sum min(k, a[i]/x) for those a[i] != (k+1)*x, k+1 otherwise
        //if (k+1) * x >= m don't test

        //let k,x; we need cut x, 2x, 4x, 8x, 16x (optimal)

        for(ll k=1;k<=m;k++){
            ll ans = 0;
            if(k >= 20){
                ans = s;
            }else{
                ll cp = 1;
                for(int i=1;i<=k;i++) cp *= 2;
                for(int x = 1; x <= m; x++){
                    //x 2x 4x 
                    //if x * cp > m, just sum it a[i] / x
                    ll cans = 0;
                    if(x * cp > m){
                        for(int j = 0; j < n; j++) cans  += a[j] / x;
                        ans = max(cans, ans);
                        break;
                    }else{
                        //if cp * x, then sum cp
                        //else sum min(cp-1, cnt[i] / x);
                        for(ll j = 1; j <= cp - 2; j++){
                            cans += (ps[x * (j+1) - 1] - ps[x * j - 1]) * j;
                        }
                        cans += (ps[m] - ps[(cp-1) * x - 1] - cnt[cp * x]) * (cp - 1);
                        cans += cp * cnt[cp * x];
                        ans = max(cans, ans);
                    }
                }
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
