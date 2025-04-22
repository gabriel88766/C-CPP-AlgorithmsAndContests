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
        vector<ll> x(n), r(n);
        for(int i=0;i<n;i++) cin >> x[i];
        for(int i=0;i<n;i++) cin >> r[i];
        ll ans = 0;
        map<int, int> mr;
        for(int i=0;i<n;i++){
            for(ll j=0;j<=r[i];j++){
                ll my = sqrt(r[i]*r[i] - j*j);
                while(my*my + j*j > r[i]*r[i]) my--;
                while((my+1)*(my+1) + j*j <= r[i] * r[i]) my++;
                mr[x[i]+j] = max(mr[x[i]+j], (int)my);
                mr[x[i]-j] = max(mr[x[i]-j], (int)my);
            }
        }
        for(auto &[k, v] : mr){
            ans += 2*v + 1;
        }
        cout << ans << "\n";
    }
}
