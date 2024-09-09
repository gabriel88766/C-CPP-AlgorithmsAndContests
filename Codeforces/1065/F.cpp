#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+3;   
int p[N], sz[N], lf[N];

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
    lf[a] += lf[b];
}

vector<int> adj[N];
vector<int> vec[N];
int anc[N];
int dp[N];
int h[N];

int  vis[N];
vector<int> adj2[N];

int ans;
void bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : adj2[u]){
            dp[v] = dp[u] + lf[v];
            ans = max(ans, dp[v]);
            q.push(v);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, k;
    cin >> n >> k;
    anc[1] = 1;
    h[1] = 0;
    for(int i=2;i<=n;i++){
        int pc;
        cin >> pc;
        anc[i] = pc;
        adj[pc].push_back(i);
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : adj[u]){
            h[v] = h[u] + 1;
            q.push(v);
        }
    }
    for(int i=1;i<=n;i++){
        if(adj[i].size() == 0){//leaf
            lf[i] = 1;
            vec[h[i]].push_back(i);
        }
    }
    for(int j=1;j<=n;j++){
        for(auto i : vec[j]){
            int cp = i;
            int ttu = 0;
            while(vis[cp] == 0){ 
                vis[cp] = ttu+1;
                unite(cp, anc[cp]);
                cp = anc[cp];
                ttu++;
                if(ttu == k) break;
            }
        }
    }
    for(int i=1;i<=n;i++) dp[get(i)] = lf[get(i)];
    ans = 0;
    for(int i=1;i<=n;i++) ans = max(ans, dp[get(i)]);
    for(int i=1;i<=n;i++){
        for(auto v : adj[i]){
            if(get(i) != get(v)){
                adj2[get(i)].push_back(get(v));
            }
        }
    }
    bfs(get(1));
    cout << ans << "\n";
}