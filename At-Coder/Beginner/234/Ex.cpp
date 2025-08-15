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
    ll n, k;
    cin >> n >> k;
    vector<tuple<int, int, int>> vp(n);
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        vp[i-1] = {a, b, i};
    }
    sort(vp.begin(), vp.end());
    int pr = 0;
    vector<pair<int, int>> ans;
    set<tuple<int, int, int>> st;
    for(int i=0;i<n;i++){
        auto [a, b, j] = vp[i];
        while(pr < n && get<0>(vp[pr]) <= a + k){
            //insert me!
            st.insert({get<1>(vp[pr]), get<0>(vp[pr]), get<2>(vp[pr])});
            pr++;
        }
        st.erase({b, a, j});
        auto it = st.lower_bound(make_tuple(b - k, 0, 0));
        while(it != st.end() && get<0>(*it) <= b + k){
            ll a1 = abs(b - get<0>(*it));
            ll a2 = abs(a - get<1>(*it));
            if(a1*a1+a2*a2<=k*k) ans.push_back({min(j, get<2>(*it)), max(j, get<2>(*it))});
            ++it;
        }
    }   
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto [a, b] : ans) cout << a << " " << b << "\n";
}
