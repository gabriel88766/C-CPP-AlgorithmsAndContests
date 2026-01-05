#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
vector<int> adj[N];
int par[N];
void bfs(int uv){
    queue<int> q;
    q.push(uv);
    while(q.size()){
        auto u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(par[v] == -1){
                par[v] = u;
                if(v == uv) break;
                q.push(v);
            }
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, int> mp;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        mp[{a, b}] = i;
    }
    vector<int> ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) par[j] = -1;
        bfs(i);
        if(par[i] != -1){
            vector<int> path;
            int cur = i;
            do{
                cur = par[cur];
                path.push_back(cur);
            }while(cur != i);
            reverse(path.begin(), path.end());
            if(ans.size() == 0) ans = path;
            else if(ans.size() > path.size()) ans = path;
        }
    }
    if(ans.size() == 0) cout << "-1\n";
    else{
        cout << ans.size() << "\n";
        for(auto x : ans) cout << x << "\n";
    }
}
