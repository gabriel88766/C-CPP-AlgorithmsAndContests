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
        int n, ans = 0;
        cin >> n;
        vector<int> v(2*n);
        vector<vector<int>> loc(n+1);
        for(int i=0;i<2*n;i++){
            cin >> v[i];
            loc[v[i]].push_back(i);
        }
        vector<bool> fb(n+1, false);
        for(int i=1;i<2*n;i++){
            if(v[i] == v[i-1]) fb[v[i]] = true;
        }
        set<pair<int, int>> st;
        for(int i=1;i<2*n;i++){
            if(v[i] != v[i-1]){
                pair<int, int> cp = {v[i], v[i-1]};
                if(cp.first > cp.second) swap(cp.first, cp.second);
                st.insert(cp);
            }
        }
        for(auto [a, b] : st){
            if(fb[a] || fb[b]) continue;
            if(abs(loc[a][0] - loc[b][0]) == 1 && abs(loc[a][1] - loc[b][1]) == 1) ans++;
        }
        cout << ans << "\n";
    }
}
