#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll xv[N];
ll cnt[60];
ll ans = 0;
vector<pair<ll, ll>> adj[N];
void dfs1(ll u, ll p){
    for(auto [v, w] : adj[u]){
        if(v == p) continue;
        xv[v] = xv[u] ^ w;
        dfs1(v, u);
    }
}
int n;
ll aux = 0;
void dfs2(ll u, ll p){
    for(int j=0;j<60;j++){
        if(aux & (1LL << j)){
            ans += (n - cnt[j]) * ((1LL << j) % MOD);
        }else{
            ans += cnt[j] * ((1LL << j) % MOD);
        }
        ans %= MOD;
    }
    for(auto [v, w] : adj[u]){
        if(v == p) continue;
        aux ^= w;
        dfs2(v, u);
        aux ^= w;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=1;i<n;i++){
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    dfs1(1, 0);
    for(int i=1;i<=n;i++){
        for(int j=0;j<60;j++){
            if(xv[i] & (1LL << j)) cnt[j]++;
        }
    }
    dfs2(1, 0);
    cout << ((ans*500000004) % MOD) << "\n";
}
