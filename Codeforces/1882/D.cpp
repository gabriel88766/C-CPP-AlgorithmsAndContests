#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
ll sub[N];
ll lb[N];
ll ans[N];
ll ans1 = 0;
int n;
void dfs1(int u = 1, int p = -1){
    sub[u] = 1;
    for(auto x: adj[u]){
        if(p != x){
            dfs1(x, u);
            sub[u] += sub[x]; 
        }
    }
    if(p != -1){
        ans1 += (lb[u] ^ lb[p]) * sub[u];
    }  
}

void dfs2(int u = 1, int p = -1){
    if(u != 1){
        ans[u] = ans[p] + (n - 2*sub[u]) * (lb[u] ^ lb[p]);
    }
    for(auto x : adj[u]){
        if(x != p) dfs2(x, u);
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
        cin >> n;
        for(int i=1;i<=n;i++) cin >> lb[i];
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs1();
        ans[1] = ans1;
        dfs2();
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
        for(int i=1;i<=n;i++){
            sub[i] = 0;
            adj[i].clear();
            ans[i] = 0;
            ans1 = 0;
        }
    }
}
