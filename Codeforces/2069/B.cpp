#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int gr[705][705];
vector<pair<int,int>> oc[500000];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=0;i<=m;i++) gr[0][i] = gr[n+1][i] = 0;
        for(int i=0;i<=n;i++) gr[i][0] = gr[i][m+1] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> gr[i][j];
                oc[gr[i][j]].push_back({i, j});
            }
        }
        int mn = 1;
        int sum = 0;
        for(int i=1;i<=n*m;i++){
            if(oc[i].size()){
                bool hs = false;
                for(auto &[a, b] : oc[i]){
                    if(gr[a+1][b] == gr[a][b] || gr[a-1][b] == gr[a][b] || gr[a][b-1] == gr[a][b] || gr[a][b+1] == gr[a][b]) hs = true;
                }
                if(hs){
                    mn = 2;
                    sum += 2;
                }else{
                    sum += 1;
                }
            }
        }
        sum -= mn;
        cout << sum << "\n";

        for(int i=1;i<=n*m;i++) oc[i].clear();
    }
}
