#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
vector<int> d1(N), d2(N);
vector<bool> ok(N);
int n;

void bfs(vector<int> &src, vector<int> &d){
    fill(d.begin(), d.begin() + n + 1, INF_INT);
    queue<int> q;
    for(auto x : src){
         d[x] = 0;
         q.push(x);
    }
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

void dfs(int u, int p){
    bool lf = true;
    if(d1[u] < d2[u]) ok[u] = true;
    else ok[u] = false;
    bool smok = false;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            if(ok[v]) smok = true;
            lf = false;
        }
    }
    if(!lf && !smok) ok[u] = false;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> n >> k;
        vector<int> fr(k);
        for(int i=0;i<k;i++) cin >> fr[i];
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> tmpaux = {1};
        bfs(tmpaux, d1);
        bfs(fr, d2);
        dfs(1, 0);
        if(ok[1]) cout << "YES\n";
        else cout << "NO\n";

        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
