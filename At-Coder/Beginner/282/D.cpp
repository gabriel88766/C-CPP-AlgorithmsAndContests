#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> vis(n+1, -1);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans = 0;
    auto bpcheck = [&](int u){
        vector<int> cmp;
        vis[u] = 0;
        cmp.push_back(u);
        ll adc = 0;
        for(int i=0;i<cmp.size();i++){
            auto u = cmp[i];
            adc += adj[u].size();
            for(auto v : adj[u]){
                if(vis[v] == -1){
                    vis[v] = vis[u] ^ 1;
                    cmp.push_back(v);
                }else if(vis[v] == vis[u]){
                    ans = -1;
                    return;
                }
            }
        }
        ll c0 = 0, c1 = 0;
        for(auto &x : cmp){
            if(vis[x] == 0) c0++;
            else c1++;
        }
        ans += c0 * (n - c0);
        ans += c1 * (n - c1);
        ans -= adc;
    };
    for(int i=1;i<=n;i++){
        if(vis[i] == -1){
            if(ans != -1){
                bpcheck(i);
            }
        }
    }
    if(ans == -1) cout << "0\n";
    else cout << ans/2 << "\n";
}
