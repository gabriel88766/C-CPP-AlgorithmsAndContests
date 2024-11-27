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
    int n;
    cin >> n;
    map<int, vector<pair<int, int>>> mp;
    for(int i=1;i<=n;i++){
        int m;
        cin >> m;
        for(int j=1;j<=m;j++){
            int p, e;
            cin >> p >> e;
            mp[p].push_back({e, i});
        }
    }
    vector<bool> us(n+1, false);
    for(auto &[k, v] : mp){
        auto mx = *max_element(v.begin(), v.end());
        int rm = mx.first;
        int cnt = 0;
        for(auto [a, b] : v){
            if(a == rm) cnt++;
        }
        if(cnt == 1){
            us[mx.second] = true;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) if(us[i]) ans++;
    if(ans != n) ans++;
    cout << ans << "\n";
}
