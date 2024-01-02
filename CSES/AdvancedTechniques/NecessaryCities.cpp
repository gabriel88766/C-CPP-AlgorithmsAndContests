#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 2e5+3;
vector<int> adj[N];
int in[N], low[N], cnt = 0;
vector<int> artp;

void dfs_artp(int u, int p = -1){
    low[u] = in[u] = ++cnt;
    int ch = 0;
    for(auto v: adj[u]){
        if(v == p) continue;
        if(!in[v]){
            dfs_artp(v, u);
            if(low[v] >= in[u] && p != -1){
                artp.push_back(u);
            }
            ch++;
            low[u] = min(low[u], low[v]);
        }else low[u] = min(low[u], in[v]);
    }
    if(p == -1 && ch > 1){
        //artic point. if removed, ch-1 more components
        artp.push_back(u);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_artp(1, -1);
    sort(artp.begin(), artp.end());
    artp.resize(unique(artp.begin(), artp.end()) - artp.begin());
    cout << artp.size() << "\n";
    for(auto x : artp){
        cout << x  << " ";
    }
}
