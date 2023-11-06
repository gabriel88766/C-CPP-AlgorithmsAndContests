#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+6; //time added
ll st[4*N];
int q;
int cr[N];
vector<int> adj[N];
vector<pair<int,int>> queries[N];
ll ans[N];


ll query(int i, int j, int l = 1, int r = q, int p = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return query(i, j, l, (l + r)/2, 2 * p) + query(i, j, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

void update(int i, ll value, int l = 1, int r = q, int p = 1){
    if(i < l || i > r) return;
    if(l == r) {st[p] = value; return;}
    update(i, value, l, (l + r)/2, 2 * p);
    update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}

void dfs(int u, int p){
    for(auto x : queries[u]){
        update(x.first, x.second);
    }
    ans[u] = query(cr[u], q);
    for(auto v: adj[u]){
        if(v != p) dfs(v, u);
    }
    for(auto x : queries[u]){
        update(x.first, 0);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        cin >> q;
        for(int i=1;i<=q;i++){
            adj[i].clear();
            queries[i].clear();
        }
        cr[1] = 1;
        int cnt = 1;
        for(int i=1;i<=q;i++){
            int type;
            cin >> type;
            if(type == 1){
                int v;
                cin >> v;
                ++cnt;
                adj[v].push_back(cnt);
                adj[cnt].push_back(v);
                cr[cnt] = i;
            }else{
                int x, v;
                cin >> v >> x;
                queries[v].push_back({i, x});
            }
        }
        dfs(1, 0);
        for(int i=1;i<=cnt;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
