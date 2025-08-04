#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 1005;   
int p[N], sz[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1;}
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
    int t;
    cin >> t;
    while(t--){
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<pair<int, int>> edg;
        vector<vector<int>> adj(n+1);
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            edg.push_back({a, b});
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1;i<=n;i++) sort(adj[i].begin(), adj[i].end());
        vector<bool> vis(n+1, false);
        vis[x] = true;
        cout << x << " ";
        int lx = x;
        while(lx != y){
            init(n);
            for(auto [a, b] : edg){
                if(vis[a] == false && vis[b] == false) unite(a, b);
            }
            for(auto nx : adj[lx]){
                if(get(nx) == get(y)){
                    cout << nx << " ";
                    lx = nx;
                    break;
                }
            }
            vis[lx] = true;
        }
        cout << "\n";
    }
}
