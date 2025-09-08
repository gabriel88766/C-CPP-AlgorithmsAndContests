#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 2e5+3;   
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
string s;
vector<int> adj[N];
vector<int> ans;

void dfs(int u, int p){
    ans.push_back(u); //n
    s[u] ^= 1;
    for(auto v : adj[u]){
        if(v == p) continue;
        dfs(v, u);
        ans.push_back(u); //n-1
        s[u] ^= 1;
    }
    if(s[u] == '1'){
        if(p != 0){
            ans.push_back(p); //n
            ans.push_back(u); //n
            s[p] ^= 1;
            s[u] ^= 1;
        }else{
            assert(ans.size());
            ans.pop_back();
        }
    }
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        if(get(a) != get(b)){
            unite(a, b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    cin >> s;
    s = " " + s;
    dfs(1, 0);
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}
