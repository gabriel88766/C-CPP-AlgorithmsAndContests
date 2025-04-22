#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
vector<int> adj[N];
int lw[N];

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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({1, 1});
    memset(lw, 63, sizeof(lw));
    lw[1] = 1;
    while(!pq.empty()){
        auto [x, u] = pq.top();
        pq.pop();
        if(lw[u] != x) continue;
        for(auto &v : adj[u]){
            if(lw[v] > max(x, v)){
                lw[v] = max(x, v);
                pq.push({lw[v], v});
            }
        }
    }
    int ml = 0;
    for(int i=1;i<=n;i++){
        for(auto &v : adj[i]) unite(i, v);
        ml = max(ml, lw[i]);
        if(ml == i) cout << sz[get(1)] - i << "\n";
        else cout << "-1\n";
    }
}
