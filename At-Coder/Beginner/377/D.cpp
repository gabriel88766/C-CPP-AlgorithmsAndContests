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
    int n, m;
    cin >> n >> m;
    vector<set<int>> vs(m+1);
    set<pair<int,int>> st;
    for(int i=1;i<=n;i++){
        int l, r;
        cin >> l >> r;
        vs[l].insert(r);
        st.insert({r, l});
    }
    ll ans = 0;
    for(int i=1;i<=m;i++){
        int mr = st.size() ? st.begin()->first - 1 : m;
        ans += mr - i + 1;
        for(auto x : vs[i]) st.erase({x, i}); 
    }
    cout << ans << "\n";
}
