#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
char c[N];
string s;
int n, m;
int p[N], sz[N];
bool ok[N], ans[N];

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
    int u, v, i;
};
vector<int> bt;
vector<Edge> v;

int prim(){
    if(bt.size() == 0) return 0;
    int w = 0;
    set<int> st;
    for(auto x : bt){
        if(ok[v[x].u] || ok[v[x].v]) continue;
        unite(v[x].u, v[x].v);
        w += 2;
        ans[x] = true;
        ok[v[x].u] = true;
        ok[v[x].v] = true;
        vector<int> aux = {v[x].u, v[x].v};
        for(auto y : aux){
            for(auto xx : adj[y]){
                auto [u, d, i] = v[xx];
                if(get(u) == get(d)) continue;
                int cnt = 0;
                if(s[u] == c[i] && !ok[u]) cnt++;
                if(s[d] == c[i] && !ok[d]) cnt++;
                if(cnt == 1) st.insert(i);
            }
        }
    }
    while(st.size()){
        int i = *st.begin();
        st.erase(st.begin());
        if(get(v[i].u) == get(v[i].v)) continue;
        if(ok[v[i].u] && ok[v[i].v]) continue;
        int nv = ok[v[i].u] ? v[i].v : v[i].u;
        unite(v[i].u, v[i].v);
        ans[v[i].i] = true;
        ok[nv] = true;
        w++;
        for(auto x : adj[nv]){
            auto [u, d, i] = v[x];
            if(get(u) == get(d)) continue;
            int cnt = 0;
            if(s[u] == c[i] && !ok[u]) cnt++;
            if(s[d] == c[i] && !ok[d]) cnt++;
            if(cnt == 1) st.insert(i);
        }
    }
    for(int i=1;i<=m;i++){
        if(get(v[i].u) != get(v[i].v)){
            unite(v[i].u, v[i].v);
            ans[i] = true;
        }
    }
    return w;   
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> m;
    init();
    v.resize(m+1);
    for(int i=1;i<=m;i++){
        cin >> v[i].u >> v[i].v >> c[i];
        adj[v[i].u].push_back(i);
        adj[v[i].v].push_back(i);
        v[i].i = i;
    }
    cin >> s;
    s = " " + s;
    for(int i=1;i<=m;i++){
        int cnt = 0;
        if(s[v[i].u] == c[i]) cnt++;
        if(s[v[i].v] == c[i]) cnt++;
        if(cnt == 2) bt.push_back(i);
    }
    auto w = prim();
    if(w != n) cout << "No\n";
    else{   
        cout << "Yes\n";
        for(int i=1;i<=m;i++) if(ans[i]) cout << i << " ";
        cout << "\n";
    }
}   
