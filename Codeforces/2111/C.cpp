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
        cin >> n;
        vector<vector<int>> oc(n+1);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            oc[x].push_back(i);
        }
        ll ans = INF_LL;
        for(int i=1;i<=n;i++){
            if(oc[i].size()){
                int p = 0;
                ll cur = 1;
                while(p < oc[i].size()){
                    int p2 = p;
                    while(p2 + 1 < oc[i].size() && oc[i][p2+1] == oc[i][p2] + 1) p2++;
                    cur = max(cur, (ll)p2 - p + 1);
                    p = p2 + 1; 
                }
                ans = min(ans, (n-cur) * i);
            }
        }
        cout << ans << "\n";
    }
}
