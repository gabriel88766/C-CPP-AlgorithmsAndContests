#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                int aux;
                cin >> aux;
                v[i].push_back(aux);
            }
        }
        vector<int> p(n, 0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            int x = 0, y = -1, qtx = 1, qty = 1;
            for(int j=1;j<n;j++){
                if(v[j][p[j]] == v[x][p[x]]) qtx++;
                else if(y == -1) y = j;
                else qty++;
            }
            if(qtx == 1) {
                ans.push_back(v[y][p[y]]);
                for(int j = 0; j<n;j++) if(j != x) p[j]++;
            }else{
                ans.push_back(v[x][p[x]]);
                for(int j = 0; j<n;j++) if(j != y) p[j]++;
            }
        }
        for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
        cout << "\n";

    }
}
