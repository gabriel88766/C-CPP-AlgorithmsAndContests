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
    vector<vector<tuple<int, int, int>>> add(n+1), rem(n+1);
    for(int i=1;i<=m;i++){
        int l, r, t, c;
        cin >> l >> r >> t >> c;
        add[l].push_back({t, i, c});
        rem[r].push_back({t, i, c});
    }
    set<tuple<int, int, int>> st;
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(auto [t, j, c] : add[i]) st.insert({t, j, c});
        if(st.size()){
            ans += get<2>(*st.begin());
        }
        for(auto [t, j, c] : rem[i]) st.erase({t, j, c});
    }
    cout << ans << "\n";
}
