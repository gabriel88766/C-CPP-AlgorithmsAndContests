#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e3+3;   
int p[N], sz[N];

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

struct Edge{
    int a, b;
    ll w;
    bool operator< (Edge v){
        if(w != v.w) return w < v.w;
        else return make_pair(a,b) < make_pair(v.a,v.b);
    }
};

vector<Edge> edges;
vector<int> adj[N], adjw[N];

void kruskal(){
    sort(edges.begin(), edges.end());
    init();
    for(auto e : edges){
        if(get(e.a) != get(e.b)){
            adj[e.a].push_back(e.b);
            adjw[e.a].push_back(e.w);
            unite(e.a, e.b);
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
    vector<vector<ll>> v(n+1,vector<ll>(n+1));
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin >> v[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            ll cur = v[i][i] + v[j][j] - 2 * v[i][j];
            if(cur % n) continue;
            edges.push_back({j, i, cur/n});
        }
    }
    kruskal();
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++){
            cout << i << " " << adj[i][j] << " " << adjw[i][j] << "\n";
        }
    }
}
