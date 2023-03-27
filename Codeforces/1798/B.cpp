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
        int m;
        cin >> m;
        map<int,int> last;
        vector<vector<int>> v;
        for(int i=0;i<m;i++){
            int n;
            cin >> n;
            vector<int> cur(n);
            for(int j=0;j<n;j++){
                cin >> cur[j];
                last[cur[j]] = i;
            }
            v.push_back(cur);
        }
        vector<int> ans(m);
        bool ok = true;
        for(int i=0;i<m;i++){
            bool ok2 = false;
            for(int j=0;j<v[i].size();j++){
                if(last[v[i][j]] == i){
                    ans[i] = v[i][j];
                    ok2 = true;
                    break;
                }
            }
            if(!ok2){
                ok = false;
                break;
            }
        }
        if(!ok) cout << "-1\n";
        else{
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }
    }
}
