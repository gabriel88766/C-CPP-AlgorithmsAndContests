#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
int rt = 1;
int n;
vector<int> adj[N];
vector<int> adi[N];
vector<int> cpath(int a, int b){
    vector<int> p(n+1);
    vector<int> edg(n+1);
    vector<bool> vis(n+1, false);
    queue<int> q;
    q.push(a);
    vis[a] = true;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            auto v = adj[u][i];
            if(!vis[v]){
                vis[v] = true;
                p[v] = u;
                edg[v] = adi[u][i];
                q.push(v);
            }
        }
    }
    int cur = b;
    vector<int> ans;
    while(cur != a){
        ans.push_back(edg[cur]);
        cur = p[cur];
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    vector<int> ans(n, 1000000);
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        adi[a].push_back(i);
        adi[b].push_back(i);
    }
    int m;
    cin >> m;
    vector<vector<int>> chk(n);
    vector<int> f(m);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b >> f[i];
        auto path = cpath(a, b);
        for(auto x : path){
            chk[x].push_back(i);
        }
    }
    //fix here, fix what ?? ¡! 
    vector<int> ok(m, false);
    for(int i=1;i<n;i++){
        vector<int> vals;
        for(auto x : chk[i]){
            vals.push_back(f[x]);
        }
        if(vals.size()){
            ans[i] = *max_element(vals.begin(), vals.end());
            for(auto x : chk[i]){
                if(f[x] == ans[i]) ok[x] = true;
            }
        }
    }
    // til here
    bool allok = true;
    for(int i=0;i<m;i++) if(!ok[i]) allok = false;
    if(allok){
        for(int i=1;i<n;i++) cout << ans[i] << " ";
        cout << "\n";
    }else cout << "-1\n";
}
