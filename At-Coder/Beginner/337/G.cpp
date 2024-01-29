#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

using namespace __gnu_pbds; //required 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 


const int N = 2e5+3;
vector<int> adj[N];
ll sub[N], cl[N], clp[N], dp[N];

int p[N];
ordered_set<int> os[N];
void init(){
    for(int i=1;i<N;i++) {p[i] = i;  os[i].insert(i);}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(os[a].size() < os[b].size()) swap(a,b);
    p[b] = a;
    for(auto x : os[b]) os[a].insert(x);
}


void dfs(int u, int p){
    sub[u] = 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            unite(u, v);
            dp[u] += dp[v] + cl[v];
            sub[u] += sub[v];
        }
    }
    cl[u] = os[get(u)].order_of_key(u);
    if(p != 0) clp[u] = os[get(u)].order_of_key(p);
}

void dfs2(int u, int p){
    for(auto v : adj[u]){
        if(v != p){
            dp[v] = dp[u] + (v - 1 - cl[v]) - clp[v];
            dfs2(v, u);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    init();
    dfs(1, 0);
    dfs2(1, 0);
    for(int i=1;i<=n;i++) cout << dp[i] << " ";
    cout << "\n";
}
