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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> gr(n, vector<int>(m));
        vector<pair<int, int>> vx;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> gr[i][j];
            }
            vx.push_back({gr[i][0], i});
        }
        sort(vx.begin(), vx.end());
        vector<int> ord;
        for(auto [a, b] : vx) ord.push_back(b);
        //in ord, must be BBBBBB RRRRR in some way
        vector<int> mx(n, 0), mn(n, INF_INT);
        vector<vector<bool>> can(n, vector<bool>(m, true));
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                mx[j] = max(mx[j], gr[ord[j]][i]);
                if(j != 0) mx[j] = max(mx[j], mx[j-1]);
            }
            for(int j=n-1;j>=0;j--){
                mn[j] = min(mn[j], gr[ord[j]][i]);
                if(j != n-1) mn[j] = min(mn[j], mn[j+1]);
            }
            for(int j=0;j<n-1;j++){
                if(mx[j] >= mn[j+1]){
                    can[j][i] = false;
                }
            }
        }
        mx.assign(n, 0), mn.assign(n, INF_INT);
        for(int i=m-1;i>0;i--){
            for(int j=0;j<n;j++){
                mn[j] = min(mn[j], gr[ord[j]][i]);
                if(j != 0) mn[j] = min(mn[j], mn[j-1]);
            }
            for(int j=n-1;j>=0;j--){
                mx[j] = max(mx[j], gr[ord[j]][i]);
                if(j != n-1) mx[j] = max(mx[j], mx[j+1]);
            }
            for(int j=0;j<n-1;j++){
                if(mn[j] <= mx[j+1]){
                    can[j][i-1] = false;
                }
            }
        }
        bool ok = false;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                if(can[i][j]){
                    cout << "YES\n";
                    string ans(n, 'R');
                    for(int k=0;k<=i;k++) ans[ord[k]] = 'B'; 
                    cout << ans << " ";
                    cout << j+1 << "\n";
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }
        if(!ok) cout << "NO\n";
    }
}
 