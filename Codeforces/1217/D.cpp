#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
vector<int> adj[N];
int vis[N];

bool dfs(int u){
    vis[u] = 1;
    bool ok = false;
    for(auto v: adj[u] ){
        if(vis[v] == 1) return true;
        else if(vis[v] == 0){
            ok |= dfs(v);
        }
    }
    vis[u] = 2;
    return ok;
}

bool dfs_cycle(int n){
    bool ok = false;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ok |= dfs(i);
        }
    }
    return ok;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> edg;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        edg.push_back({a, b});
        adj[a].push_back(b);
    }
    if(dfs_cycle(n)){
        cout << "2\n";
        for(auto [a, b] : edg){
            if(a < b) cout << "1 ";
            else cout << "2 ";
        }
        cout << "\n";
    }else{
        cout << "1\n";
        for(int i=0;i<m;i++) cout << "1 ";
        cout << "\n";
    }
}
