#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
int d[N][N];
bool ispl[N][N];
vector<int> adj[N];
vector<pair<int, int>> alld[N];

int p[N], sz[N], xv[N], cnt = 0;

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
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char x;
            cin >> x;
            if(x == '1') ispl[i][j] = true;
            if(i == j) ispl[i][j] = true;
        }
    }
    //calculating distances
    memset(d, 63, sizeof(d));
    int md = 0;
    for(int i=1;i<=n;i++){
        queue<int> q;
        q.push(i);
        d[i][i] = 0;
        while(q.size()){
            auto u = q.front();
            q.pop();
            md = max(md, d[i][u]);
            for(auto &v : adj[u]){
                if(d[i][v] > d[i][u] + 1){
                    d[i][v] = d[i][u] + 1;
                    q.push(v);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            alld[d[i][j]].push_back({i, j});
        }
    }
    //first, check all possible x[u] = x[v] because of some greater palin 
    //decreasing distances
    for(int i=md;i>=0;i--){
        for(auto &[u, v] : alld[i]){
            if(ispl[u][v]) continue;
            for(auto &x : adj[u]){
                for(auto &y : adj[v]){
                    if(d[x][y] == d[u][v] + 2 && ispl[x][y]){
                        ispl[u][v] = true;
                    }
                }
            }
        }
    }
    //now dsu
    init();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ispl[i][j]) unite(i, j);
        }
    }
    for(int i=1;i<=n;i++){
        if(xv[get(i)]) xv[i] = xv[get(i)];
        else xv[i] = xv[get(i)] = ++cnt;
    }
    //now solve
    for(int i=1;i<=md;i++){
        for(auto &[u, v] : alld[i]){
            if(ispl[u][v]) continue;
            if(i == 1){
                if(xv[u] == xv[v]) ispl[u][v] = true;
                continue;
            }
            for(auto &x : adj[u]){
                for(auto &y : adj[v]){
                    if(d[x][y] + 2 == d[u][v] && ispl[x][y] && xv[u] == xv[v]){
                        ispl[u][v] = true;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ispl[i][j]) ans++;
        }
    }
    cout << ans << "\n";
}
