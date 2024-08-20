#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct interv{
    int l, r, i;
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int, vector<int>> mp;
        vector<int> a(n), b(n), x(n), aa(n), ab(n);
        for(int i=0;i<n;i++){
            cin >> a[i] >> b[i] >> x[i];
            mp[a[i]+b[i]-x[i]].push_back(i);
        }
        ll ans = 0;
        for(auto [k, vec] : mp){
            vector<interv> vp;
            for(auto j : vec){
                int mna = max(0, a[j]-x[j]);
                int mxa = a[j] - max(x[j] - b[j], 0);
                vp.push_back({mna, mxa, j});
            }
            sort(vp.begin(), vp.end(), [&](interv &ax, interv &bx){
                return ax.r < bx.r;
            });
            set<int> s;
            for(auto [l, r, j] : vp){
                auto it = s.lower_bound(l);
                if(it == s.end()) s.insert(r);
                else assert(*it <= r);
            }
            ans += s.size();
            for(auto [l, r, j]:vp){
                auto it = s.lower_bound(l);
                assert(it != s.end() && *it <= r);
                aa[j] = a[j] - *it;
                ab[j] = x[j] - aa[j];
            }
        }
        cout << ans << "\n";
        for(int i=0;i<n;i++){
            cout << aa[i] << " " << ab[i] << "\n";
        }
    }
}
