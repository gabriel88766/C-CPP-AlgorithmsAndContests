#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

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
        vector<vector<bool>> used(n, vector<bool>(m, false));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> v(n, vector<int>(m));
        vector<pair<int,int>> check;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> v[i][j];
                if(v[i][j]){
                    check.push_back({i, j});
                    used[i][j] = true;
                }
            }
        }
        bool ok = true;
        for(int i=0;i<check.size();i++){
            int x = check[i].first, y = check[i].second;
            int cnt = 0;
            for(int j=0;j<4;j++){
                int xd = x + dx[j];
                int yd = y + dy[j];
                if(xd < 0 || xd >= n || yd < 0 || yd >= m) continue;
                if(cnt < v[x][y]){
                    cnt++;
                    used[xd][yd] = true;
                }
            }
            if(cnt != v[x][y]) ok = false;
        }
        if(ok){
            cout << "YES\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(used[i][j]){
                        for(int k=0;k<4;k++){
                            int xd = i + dx[k];
                            int yd = j + dy[k];
                            if(xd < 0 || xd >= n || yd < 0 || yd >= m) continue;
                            if(used[xd][yd]) ans[i][j]++;
                        }
                    }
                    cout << ans[i][j] << " ";
                }
                cout << "\n";
            }
        }else cout << "NO\n";
    }
}
