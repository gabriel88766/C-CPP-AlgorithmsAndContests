#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+4;
vector<int> adj[N];
int tag[N], sz[N], cnt = 0;

void dfs(int u){
    tag[u] = ++cnt;
    sz[u] = 1;
    for(auto v : adj[u]){
        if(!tag[v]){
            dfs(v);
            sz[u] += sz[v];
        }
    }
}

ll bit[N];
ll v[N];
int n;
 
ll query(int b){ // sum in range [1, b]
    ll ans = 0;
    for(int i = b; i > 0; i -= i & -i){
        ans += bit[i];
    }
    return ans;
}

ll query(int a, int sz){
    return query(a+sz-1) - query(a-1);
}
 
void add(int b, ll value){ //add value to position b
    for(int i = b; i <= n; i += i & -i){
        bit[i] += value;
    }
}
 
void build(){
    for(int i=1;i<=n;i++) add(i, v[i]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int q;
    cin >> n >> q;
    vector<ll> aux(n+1);
    for(int i=1;i<=n;i++) cin >> aux[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1); 
    for(int i=1;i<=n;i++){
        v[tag[i]] = aux[i];
    }
    build();
    for(int i=1;i<=q;i++){
        int a;
        cin >> a;
        if(a == 1){
            ll s, x, c;
            cin >> s >> x;
            c = query(tag[s], 1);
            add(tag[s], x-c);
        }else{
            int c;
            cin >> c;
            cout << query(tag[c], sz[c]) << "\n";
        }
    }
}
