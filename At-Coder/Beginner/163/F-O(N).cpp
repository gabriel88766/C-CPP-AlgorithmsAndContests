#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int c[N], sub[N], cnt[N];
ll ans[N];
int n;

int t = 0;
int ord[N], inv[N];
vector<int> st[N];
void dfs(int u, int p){
    ord[u] = ++t;
    inv[t] = u;
    sub[u] = 1;
    int x = c[u];
    ll cur = 1;
    ll curans = 1;
    ll curct = 0;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            sub[u] += sub[v];
            ll aux = sub[v];
            while(st[x].size() && st[x].back() >= ord[v] && st[x].back() <= ord[v] + sub[v] - 1){
                aux -= sub[inv[st[x].back()]];
                curct += sub[inv[st[x].back()]];
                st[x].pop_back();
            }
            curans += aux * cur;
            cur += aux;
        }
    }
    ll pt = n - sub[u] - cnt[x] + curct;
    curans += cur * pt;
    ans[x] += curans;
    cnt[x] += sub[u] - curct;
    st[x].push_back(ord[u]);
}



//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
}
