#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
ll p[N], sz[N];
ll ans[N];
vector<pair<int,int>> adj[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m;
    cin >> n >> m;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[c].push_back({a,b});
    }
    ll S = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++){
            int u = get(adj[i][j].first), v = get(adj[i][j].second);
            if(u == v) continue;
            else{
                S += ((sz[u]+sz[v]) * (sz[u] + sz[v]-1))/2 - (sz[u]*(sz[u]-1))/2 - (sz[v]*(sz[v]-1))/2;
                unite(u, v);
            }
        }
        ans[i] = S;
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        cout << ans[x] << " ";
    }
}
