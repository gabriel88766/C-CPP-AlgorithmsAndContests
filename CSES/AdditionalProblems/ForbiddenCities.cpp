#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+2;
vector<int> adj[N];
int ans[N], artp[N], low[N], in[N];
set<int> st[N];
int cnt;
/*struct Query{
    int l, r, j;
};
vector<Query> vq[N];*/

void dfs_artp(int u, int p = -1){
    low[u] = in[u] = ++cnt;
    int ch = 0;
    for(auto v: adj[u]){
        if(v == p) continue;
        if(!in[v]){
            dfs_artp(v, u);
            if(low[v] >= in[u] && p != -1){
                st[u].insert(low[v]);
                artp[u] = true;
            }
            ch++;
            low[u] = min(low[u], low[v]);
        }else low[u] = min(low[u], in[v]);
    }
    if(p == -1 && ch > 1){
        //artic point. if removed, ch-1 more components
        artp[u] = true;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    adj[0].push_back(1);
    adj[1].push_back(0);
    dfs_artp(0);
    for(int i=0;i<q;i++){
        int l, r, c;
        cin >> l >> r >> c;
        if(!artp[c]) cout << "YES\n";
        else{
            auto it1 = st[c].upper_bound(in[l]);
            auto it2 = st[c].upper_bound(in[r]);
            if(it1 == it2) cout << "YES\n";
            else cout << "NO\n";
        }
    }

}
