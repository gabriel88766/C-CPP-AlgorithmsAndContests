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
    int t;
    cin >> t;
    while(t--){
        map<ll, vector<ll>> adj;
        int n;
        cin >> n;
        ll src = n;
        for(int i=1;i<=n;i++){
            ll x;
            cin >> x;
            ll s = x - 1 + i;
            ll d = s + i-1;
            adj[s].push_back(d);
        }
        map<ll, bool> vis;
        queue<ll> q;
        q.push(src);
        vis[src] = true;
        ll ans = src;
        while(!q.empty()){
            auto u =q.front();
            q.pop();
            if(adj.count(u)){
                for(auto v : adj[u]){
                    if(!vis[v]){
                        vis[v] = true;
                        ans = max(ans, v);
                        q.push(v);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
