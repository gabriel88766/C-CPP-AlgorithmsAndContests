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
        int n;
        ll S;
        cin >> n >> S;
        vector<ll> ps(n+1);
        for(int i=1;i<=n;i++){
            cin >> ps[i];
            ps[i] += ps[i-1];
        }
        if(ps[n] <= S){
            cout << "0\n";
            continue;
        }
        int mg = 0, ans = 0;
        for(int i=1;i<=n+1;i++){
            if(ps[i-1] > S) break;
            ll gs = S + (ps[i] - ps[i-1]);
            int ind = prev(lower_bound(ps.begin(), ps.end(), gs + 1)) - ps.begin();
            // cout << ind << " ";
            if(ind - 1 > mg){
                mg = ind - 1;
                ans = i;
            }
        }
        if(ans == n+1) ans = 0;
        cout << ans << "\n";
    }
}
