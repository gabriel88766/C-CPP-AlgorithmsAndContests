#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> adj[N], invadj[N];
bool vis[N];

void dfs(int u){
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs(i);
        }
    }
}
void dfs_2(int u){
    vis[u] = true;
    for(auto i : invadj[u]){
        if(!vis[i]){
            dfs_2(i);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        invadj[b].push_back(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout << "NO\n";
            cout << 1 << " " << i << "\n";
            return 0;
        }
        vis[i] = 0;
    }
    dfs_2(1);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout << "NO\n";
            cout << i << " " << 1 << "\n";
            return 0;
        }
    }
    cout << "YES";
}
