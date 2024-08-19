#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

map<string, int> mp = {{"BG", 0}, {"BR", 1}, {"BY", 2}, {"GR", 3}, {"GY", 4}, {"RY", 5}};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<vector<int>> v(6);
        vector<string> s(n+1);
        for(int i=1;i<=n;i++){
            cin >> s[i];
            assert(mp.count(s[i]));
            v[mp[s[i]]].push_back(i);
        }
        for(int i=0;i<q;i++){
            int a, b;
            cin >> a >> b;
            int ans = INF_INT;
            if(s[a][0] == s[b][0] || s[a][1] == s[b][0] || s[a][0] == s[b][1] || s[a][1] == s[b][1]) ans = abs(b-a);
            else{
                for(auto [str, val] : mp){
                    if(str != s[a] && str != s[b]){
                        if(v[val].size() == 0) continue;
                        auto it = lower_bound(v[val].begin(), v[val].end(), a);
                        if(it != v[val].end()){
                            ans = min(ans, abs(a - *it) + abs(b - *it));
                        }
                        if(it != v[val].begin()){
                            ans = min(ans, abs(a - *prev(it)) + abs(b - *prev(it)));
                        }
                    }
                }
            }
            if(ans == INF_INT) cout << "-1\n";
            else cout << ans << "\n";
        }
    }
}
