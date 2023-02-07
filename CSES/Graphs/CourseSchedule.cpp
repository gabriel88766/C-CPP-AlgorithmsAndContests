#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
bool visited[N];

vector<int> topo;

int color[N];

bool match = false;
void dfs1(int u){
    if(match) return;
    color[u] = 1;
    for(auto i : adj[u]){
        if(color[i] == 0){
            dfs1(i);
        }else if(color[i] == 1) match = true;
    }
    color[u] = 2;
}

void dfs2(int u){
    visited[u] = true;
    for(auto i : adj[u]){
        if(!visited[i]){
            dfs2(i);
        }
    }
    topo.push_back(u);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    int m;
    cin >> m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!color[i]) dfs1(i);
    }
    if(match){
        cout << "IMPOSSIBLE";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]) dfs2(i);
    }
    reverse(topo.begin(), topo.end());
    for(int i=0;i<topo.size();i++) cout << topo[i] << " ";
}
