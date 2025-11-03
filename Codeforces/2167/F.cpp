#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int sub[N];

void dfs1(int u, int p){
    sub[u] = 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs1(v, u);
            sub[u] += sub[v];
        }
    }
}
ll ans = 0, cq = 0;
int k;

void change(int pos, int val){
    if(sub[pos] >= k) cq--;
    sub[pos] += val;
    if(sub[pos] >= k) cq++;
}

void solve(int u, int p){
    ans += cq;
    for(auto v : adj[u]){
        if(v != p){
            change(u, -sub[v]);
            change(v, sub[u]);
            solve(v, u);
            change(v, -sub[u]);
            change(u, sub[v]);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n >> k;
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs1(1, 0);
        ans = 0;
        cq = 0;
        for(int i=1;i<=n;i++) if(sub[i] >= k) cq++;
        solve(1, 0);
        cout << ans << "\n";
        //clear
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
    }
}
