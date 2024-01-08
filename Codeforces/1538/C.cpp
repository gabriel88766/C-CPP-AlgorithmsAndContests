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
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        ll ans = 0;
        for(int i=0;i<n-1;i++){
            int rr = r - v[i]+1;
            int rl = l - v[i];
            rl = max(rl, v[i]);
            if(rr >= rl){
                ans += lower_bound(v.begin()+i+1, v.end(), rr) - lower_bound(v.begin()+i+1, v.end(), rl);
            }
        }
        cout << ans << "\n";
    }
}
