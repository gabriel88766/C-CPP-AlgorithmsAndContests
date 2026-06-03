#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
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

int adj[N][N];
int d[N][N];
vector<pair<int, int>> radj[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n;
    cin >> n;
    vector<tuple<int, int, int>> vx;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cin >> adj[i][j];
            vx.push_back({adj[i][j], i, j});
        }
    }
    sort(vx.begin(), vx.end());
    for(auto [val, u, v] : vx){
        if(get(u) != get(v)){
            unite(u, v);
            radj[u].push_back({v, val});
            radj[v].push_back({u, val});
        }
    }
    memset(d, 63, sizeof(d));
    for(int i=1;i<=n;i++){
        d[i][i] = 0;
        queue<int> q;
        q.push(i);
        while(q.size()){
            auto u = q.front();
            q.pop();
            for(auto [v, dx] : radj[u]){
                if(d[i][v] > d[i][u] + dx){
                    d[i][v] = d[i][u] + dx;
                    q.push(v);
                }
            }
        }
    }
    bool ok = true;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(d[i][j] != adj[i][j]) ok = false;
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
