#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
vector<int> adj[N];
int col[N];
vector<vector<vector<int>>> vs;

char dp[N][N], p[N][N]; //first or second
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int a = n1 + n3;
    int b = n2;
    //make bipartites..
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> xxx;
    vs.push_back(xxx);
    bool ok = true;
    for(int i=1;i<=n;i++){
        if(!col[i]){
            //try bipartite
            queue<int> q;
            q.push(i);
            vector<int> vv;
            vv.push_back(i);
            col[i] = 2; //colors 2 and 3
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    if(col[v]){
                        if(col[v] == col[u]){
                            //not bipartite
                            ok = false;
                        }
                    }else{
                        col[v] = col[u] ^ 1;
                        vv.push_back(v);
                        q.push(v);
                    }
                }
            }
            vector<vector<int>> cur(2);
            for(auto x : vv){
                if(col[x] == 2) cur[0].push_back(x);
                else cur[1].push_back(x);
            }
            vs.push_back(cur);
        }
    }
    if(ok){
        //try sum to a and b
        dp[0][0] = 1;
        for(int i=1;i<vs.size();i++){
            for(int j=0;j<=n;j++){
                if(dp[i-1][j]){
                    dp[i][j+vs[i][0].size()] = 1;
                    p[i][j+vs[i][0].size()] = 0;
                    dp[i][j+vs[i][1].size()] = 1;
                    p[i][j+vs[i][1].size()] = 1;
                }
            }
        }
        if(dp[vs.size()-1][n2]){
            //is possible
            cout << "YES\n";
            string ans(n, '.');
            int u = n2;
            for(int i=vs.size()-1;i>=1;i--){
                int par = p[i][u];
                for(auto x : vs[i][par]) ans[x-1] = '2';
                for(auto x : vs[i][par^1]) ans[x-1] = '1';
                u -= vs[i][par].size();
            }
            for(int i=0;i<ans.size();i++){
                if(ans[i] == '1' && n3){
                    ans[i] = '3';
                    n3--;
                }
            }
            cout << ans << "\n";
        }else cout << "NO\n";
    }else cout << "NO\n";
}
