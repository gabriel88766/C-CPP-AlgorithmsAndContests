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
        int n, m, k, w;
        cin >> n >> m >> k >> w;
        vector<ll> v(w);
        for(int i=0;i<w;i++) cin >> v[i];
        sort(v.begin(), v.end(), greater<ll>());
        vector<ll> cn;
        ll ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ll mni = max(0, i-k+1), mxi = min(n-k, i);
                ll mnj = max(0, j-k+1), mxj = min(m-k, j);
                cn.push_back((mxi-mni+1) * (mxj-mnj+1)); 
            }
        }
        sort(cn.begin(), cn.end(), greater<ll>());
        for(int i=0;i<v.size();i++){
            ans += v[i] * cn[i];
        }
        cout << ans << "\n";
    }
}
