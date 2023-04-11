#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+6;
vector<int> adj[N];
ll st[4*N];
ll v[N];
int sub[N], ord[N];
int n, cnt=0;

ll query(int i, int j, int l = 1, int r = n, int p = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return query(i, j, l, (l + r)/2, 2 * p) + query(i, j, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

void update(int i, ll value, int l = 1, int r = n, int p = 1){
    if(i < l || i > r) return;
    if(l == r) {st[p] += value; return;}
    update(i, value, l, (l + r)/2, 2 * p);
    update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}

void dfs(int u, int p = 0){
    ord[u] = ++cnt;
    sub[u]++;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            sub[u] += sub[v];
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int  q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    //build
    for(int i=1;i<=n;i++){
         update(ord[i], v[i]);
         update(ord[i]+sub[i], -v[i]);
    }
    for(int i=1;i<=q;i++){
        int a;
        cin >> a;
        if(a==1){
            int b,c;
            cin >> b >> c;
            update(ord[b], c-v[b]);
            update(ord[b]+sub[b], v[b]-c);
            v[b] = c;
        }else{
            int b;
            cin >> b;
            cout << query(1,ord[b]) << "\n";
        }
    }
}
