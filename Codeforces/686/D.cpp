#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3, M = 20;
vector<int> adj[N];
int sub[N];
int ch[N][M];
void dfs(int u){
    sub[u] = 1;
    for(auto v : adj[u]){
        dfs(v);
        sub[u] += sub[v];
    }
    for(auto v : adj[u]){
        if(sub[v] > sub[ch[u][0]]) ch[u][0] = v;
    }
    for(int j=1;j<M;j++){
        ch[u][j] = ch[ch[u][j-1]][j-1];
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=2;i<=n;i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    dfs(1);
    //approach:
    //find the deepest child with subtree >= sub[u] / 2;
    //it is also the subtree with lowest value but value is greater or equal to  sub[u] / 2
    for(int i=1;i<=q;i++){
        int u;
        cin >> u;
        int v = u;
        int g = (sub[u] + 1) / 2;
        for(int j=M-1;j>=0;j--){
            if(sub[ch[v][j]] >= g) v = ch[v][j];
        }
        cout << v << "\n";
    }
}
