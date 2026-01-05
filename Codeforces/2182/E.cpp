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
        vector<ll> a(m);
        for(int i=0;i<m;i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<tuple<ll,ll,ll>> cds;
        for(int i=0;i<n;i++){
            ll x, y, z;
            cin >> x >> y >> z;
            z -= y;
            k -= y;
            cds.push_back({x, z, i});
        }
        sort(cds.begin(), cds.end());
        vector<bool> sc(n, false);
        set<pair<ll, ll>> st;
        int p = 0;
        for(auto x : a){
            //try to put the more expensive possible gift here
            while(p < n && get<0>(cds[p]) <= x){
                st.insert({get<1>(cds[p]), get<2>(cds[p])});
                p++;
            }
            if(st.size()){
                auto el = *prev(st.end());
                st.erase(prev(st.end()));
                sc[el.second] = true;
            }
        }
        sort(cds.begin(), cds.end(), [&](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b){
            return get<1>(a) < get<1>(b);
        });
        for(auto [a, b, j] : cds){
            if(k >= b && sc[j] == false){
                sc[j] = true;
                k -= b;
            }
        }
        int ans = 0;
        for(int j=0;j<n;j++) if(sc[j]) ans++;
        cout << ans << "\n";
    }
}
