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
        vector<vector<int>> v;
        vector<int> in(51, 0);
        for(int i=0;i<n;i++){
            int m;
            cin >> m;
            vector<int> curs(m);
            for(int j=0;j<m;j++){
                cin >> curs[j];
                in[curs[j]]++;
            }
            v.push_back(curs);
        }
        int ans = 0;
        for(int i=1;i<=50;i++){
            if(!in[i]) continue;
            int cur = 0;
            vector<bool> incur(51, false);
            for(int j=0;j<n;j++){
                auto it = lower_bound(v[j].begin(), v[j].end(), i);
                if(it != v[j].end() && *it == i) continue;
                for(int k=0;k<v[j].size();k++) incur[v[j][k]] = true;
            }
            for(int j=1;j<=50;j++) if(incur[j]) cur++;
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
}
