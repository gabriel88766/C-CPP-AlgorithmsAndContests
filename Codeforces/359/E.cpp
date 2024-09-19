#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char cc[] = {'D', 'R', 'U', 'L'};
const int N = 505;
int gr[N][N];
int ps[N][N];
int vis[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, xs, ys;
    cin >> n >> xs >> ys;
    //do dfs, find if all "1" in same component, go back to xs, ys, do a dfs;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> gr[i][j];
            ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + gr[i][j];
        }
    }
    string ans = "";
    stack<tuple<int,int,int>> st;
    st.push({xs, ys, -1});
    vis[xs][ys] = true;
    auto check = [&](int x, int y){
        if(x < 1 || x > n || y < 1 || y > n) return false;
        else return true;
    };
    while(!st.empty()){
        auto [x, y, ccc] =  st.top();
        if(gr[x][y] == 0){
            gr[x][y] = 1;
            ans += '1';
        }
        bool kg = false;
        for(int k=0;k<4;k++){
            int xd = x + dx[k];
            int yd = y + dy[k];
            if(!check(xd, yd)) continue;
            if(vis[xd][yd]) continue;
            bool ok = false;
            if(dx[k] == 1){
                if(ps[n][y] - ps[n][y-1] - ps[x][y] + ps[x][y-1] >= 1) ok = true;
            }else if(dx[k] == -1){
                if(ps[x-1][y] - ps[0][y] - ps[x-1][y-1] + ps[0][y-1] >= 1) ok = true;
            }else if(dy[k] == 1){
                if(ps[x][n] - ps[x][y] - ps[x-1][n] + ps[x-1][y] >= 1) ok = true;
            }else{
                if(ps[x][y-1] - ps[x][0] - ps[x-1][y-1] + ps[x-1][0] >= 1) ok = true;
            }
            if(ok){
                kg = true;
                ans += cc[k];
                vis[xd][yd] = true;
                st.push({xd, yd, k^2});
                break;
            }
        }
        if(!kg){
            if(ccc != -1) ans += cc[ccc];
            st.pop(); 
        }
    }
    bool isok = true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(gr[i][j] && (!vis[i][j])) isok = false;
        }
    }
    if(isok){
        //now go dfs
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                vis[i][j] = false;
            }
        }
        vis[xs][ys] = 1;
        function<void(pair<int,int>, int)> dfs = [&](pair<int,int> u, int xx){
            auto [x, y] = u;
            for(int k=0;k<4;k++){
                int xd = x + dx[k];
                int yd = y + dy[k];
                if(!check(xd, yd)) continue;
                if(!gr[xd][yd]) continue;
                if(vis[xd][yd]) continue;
                vis[xd][yd] = true;
                ans += cc[k];
                dfs(make_pair(xd, yd), k^2);
            }
            ans += '2';
            if(xx != -1) ans += cc[xx];
        };
        dfs(make_pair(xs, ys), -1);
        cout << "YES\n";
        cout << ans << "\n";
    }else cout << "NO\n";

}
