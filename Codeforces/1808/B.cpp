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
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> v(m, vector<ll>(n));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin  >> v[j][i];
        ll ans = 0;
        for(int i=0;i<m;i++) sort(v[i].begin(), v[i].end());
        for(int i=0;i<m;i++){
            vector<ll> ps(n+1,0);
            for(int j=1;j<=n;j++) ps[j] = ps[j-1] + v[i][j-1];
            for(int j=1;j<=n;j++){
                ans += (ps[n]-ps[j])-(n-j)*v[i][j-1];
                ans += (j-1) * v[i][j-1] - ps[j-1];
            }
        }
        cout << ans/2 << "\n";
    }
}
