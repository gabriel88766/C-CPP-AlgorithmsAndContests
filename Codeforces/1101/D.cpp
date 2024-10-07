#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N], divs[N];
map<int,int> mp[N];
int a[N];
int ans = 0;

void dfs(int u, int par = 0){
    if(a[u] != 1){
        mp[u][a[u]] = 1;
        ans = max(ans, 1);
    }
    
    for(auto v : adj[u]){
        if(v != par){
            dfs(v, u);
            vector<pair<int,int>> ins;
            for(auto [k, d] : mp[v]){
                int g = gcd(k, a[u]);
                if(g != 1){
                    for(auto [k2, x2] : mp[u]){
                        if(gcd(k2, g) != 1) ans = max(ans, x2 + d);
                    }
                    ins.push_back({g, d+1});
                }
            }

            for(auto [g, d] : ins){
                mp[u][g] = max(mp[u][g], d);
            }
        }
    } 
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cout << ans << "\n";
}
