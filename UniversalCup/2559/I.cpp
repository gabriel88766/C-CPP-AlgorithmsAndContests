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
    //freopen("in", "r", s  tdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n+1);
        vector<int> q(n+1);
        for(int i=1;i<=n;i++) cin >> p[i];
        for(int i=1;i<=n;i++) cin >> q[i];
        vector<pair<int, int>> ans;
        vector<bool> vis(n+1);

        for(int i=n;i>=1;i--){
            int cj, pj;
            for(int j=1;j<=n;j++) if(p[j] == i) cj = j;
            for(int j=1;j<=n;j++) if(q[j] == i) pj = j;
            if(cj < pj) break;
            int cv = 0;
            vector<int> pls;
            for(int j=pj;j<=cj;j++){
                if(p[j] > cv && p[cj] >= p[j]){
                    pls.push_back(j);
                    cv = p[j];
                }
            }
            for(int j=pls.size() - 1; j > 0; j--){
                ans.push_back({pls[j-1], pls[j]});
                swap(p[pls[j-1]], p[pls[j]]);
            }
        }



        if(p == q){
            cout << "YES\n";
            cout << ans.size() << "\n";
            for(auto [a, b] : ans) cout << a << " " << b << "\n";
        }else{
            cout << "NO\n";
        }
    }
}
