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
        int n, k;
        cin >> n >> k;
        vector<ll> v(n), sl(k+1, 0), sm(k+1, 0);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        ll S = 0;
        for(int i=0;i<n;i++) S += v[i];
        for(int i=1;i<=k;i++){
            sl[i] = sl[i-1];
            sm[i] = sm[i-1];
            sl[i] += v[2*i-2];
            sl[i] += v[2*i-1];
            sm[i] += v[n-i];
        }
        ll ans = 0;
        for(int i=0;i<=k;i++){
            ans = max(ans, S-sl[i] - sm[k-i]);
        }
        cout << ans << "\n";
        
    }
}
