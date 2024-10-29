#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
vector<int> adj[N], adji[N];
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

int v[N], vis[N];
pair<int,int> sw[200005];
vector<int> curv;
void dfs(int u, int p){
    vis[u] = true;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
        }
    }
    curv.push_back(u);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    int m;
    cin >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        if(get(a) != get(b)){
            unite(a, b);
            adj[a].push_back(b);
            adj[b].push_back(a);
            adji[a].push_back(i);
            adji[b].push_back(i);
            sw[i] = {a, b};
        }
    }
    bool ok = true;
    vector<int> swl;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            curv.clear();
            dfs(i, 0);
            vector<int> aux;
            for(auto x : curv) aux.push_back(v[x]);
            auto aux2 = curv;
            sort(aux2.begin(), aux2.end());
            sort(aux.begin(), aux.end());
            if(aux != aux2){
                ok = false;
                break;
            }
            for(auto x : curv){
                int pos = -1;
                for(auto y : curv){
                    if(v[y] == x) pos = y;
                }
                //BFS to reach swap pos to x
                if(pos == x) continue;
                queue<int> q;
                q.push(pos);
                vector<int> d(n+1, INF_INT);
                d[pos] = 0;
                vector<pair<int,int>> par(n+1);
                while(!q.empty()){
                    auto u = q.front();
                    q.pop();
                    for(int i=0;i<adj[u].size();i++){
                        int v = adj[u][i];
                        int j = adji[u][i];
                        if(d[v] > d[u] + 1){
                            d[v] = d[u] + 1;
                            par[v] = {u, j};
                            q.push(v);
                        }
                    }
                }
                int cur = x;
                vector<int> csw;
                while(cur != pos){
                    csw.push_back(par[cur].second);
                    cur = par[cur].first;
                }
                reverse(csw.begin(), csw.end());
                for(auto x : csw){
                    swl.push_back(x);
                    swap(v[sw[x].first], v[sw[x].second]);
                }
            }

        }
    }
    if(ok){
        cout << swl.size() << "\n";
        for(auto x : swl) cout << x << " ";
        cout << "\n";
    }else cout << "-1\n";
}
