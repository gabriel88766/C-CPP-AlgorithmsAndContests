#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
bool vis[N];
void dfs(int u){
    vis[u] = true;
    for(auto x : adj[u]){
        if(!vis[x]) dfs(x);
    }
}

int p[N], sz[N], str[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1; str[i]=0;}
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
    str[a] += str[b];
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
        int n, m;
        cin >> n >> m;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=0;i<m;i++){
            int u,v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        bool ok = true;
        dfs(1);
        for(int i=1;i<=n;i++) if(!vis[i]) ok = false;
        if(!ok){
            cout << "NO\n";
            for(int i=1;i<=n;i++) { adj[i].clear(); vis[i] = false;}
            continue;
        }
        init(n);

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        for(int i=1;i<=n;i++) vis[i] = false;
        for(int i=1;i<=n;i++){
            if(a[i] == 0){
                str[i] = 1;
                vis[i] = true;
                for(auto x : adj[i]){
                    pq.push({a[x]-1, {i, x}});
                }
            }
        }
        
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            if(str[get(u.second.first)] >= a[u.second.second]){
                if(a[u.second.second]){
                    str[get(u.second.first)]++;
                    a[u.second.second] = 0;
                }
                unite(u.second.first, u.second.second);
                if(!vis[u.second.second]){
                    for(auto x : adj[u.second.second]){
                        pq.push({a[x]-str[get(u.second.second)], {u.second.second, x}});
                    }
                    vis[u.second.second] = true;
                }
            }
        }


        if(str[get(1)] != n) ok = false;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
        for(int i=1;i<=n;i++) { adj[i].clear(); vis[i] = false;}
    }
}
