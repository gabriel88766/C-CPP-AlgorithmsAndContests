#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;   
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

vector<int> adj[N], adjw[N];
bool vis[N], inf[N];
ll d[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        adjw[a].push_back(c);
        adjw[b].push_back(-c);
        unite(a, b);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i] = true;
            d[i] = 0;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                for(int i=0;i<adj[u].size();i++){
                    auto &v = adj[u][i];
                    auto &w = adjw[u][i];
                    if(!vis[v]){
                        vis[v] = true;
                        d[v] = d[u] + w;
                        q.push(v);
                    }else if(d[v] != d[u] + w){
                        inf[get(u)] = true;
                        break;
                    }
                }
            }
        }
    }
    

    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a >> b;
        if(get(a) != get(b)) cout << "nan\n";
        else if(inf[get(a)]) cout << "inf\n";
        else cout << d[b] - d[a] << "\n";
    }
}
