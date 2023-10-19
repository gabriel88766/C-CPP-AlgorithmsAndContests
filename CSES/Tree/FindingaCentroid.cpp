#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];

// n #nodes in tree
int centroid(int n){
    vector<int> sub(n+1, 0);
    vector<int> par(n+1, 0);
    function<void(int,int)> dfs = [&](int u, int p) {
        sub[u] += 1;
        par[u] = p;
        for(auto v : adj[u]){
            if(v != p){
                dfs(v, u);
                sub[u] += sub[v];
            }
        }
    };
    dfs(1,0);
    int ans = 1;
    while(true){
        int nxt = -1;
        for(auto v : adj[ans]){
            if(sub[v] > n/2 && v != par[ans]){
                nxt = v;
            }
        }
        if(nxt == -1) break;
        else ans = nxt;
    }
    return ans;
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
    cout << centroid(n) << "\n";
}
