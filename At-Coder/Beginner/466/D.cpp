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
    vector<set<int>> ro(n+1), co(n+1);
    for(int i=1;i<=m;i++){
        int r, c;
        cin >> r >> c;
        vector<pair<int, int>> rml;
        for(auto cc : ro[r]){
            rml.push_back({r, cc});
        }
        for(auto rr : co[c]){
            rml.push_back({rr, c});
        }
        for(auto [rr, cc] : rml){
            ro[rr].erase(cc);
            co[cc].erase(rr);
        }
        ro[r].insert(c);
        co[c].insert(r);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans += ro[i].size();
    }
    cout << ans << "\n";
}
