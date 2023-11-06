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
        ll S;
        int n;
        cin >> n >> S;
        vector<vector<ll>> adj(n+1), adjw(n+1), adjc(n+1);
        vector<ll> cl(n+1); 
        for(int i=1;i<n;i++){
            int a, b, w, c;
            cin >> a >> b >> w >> c;
            adj[a].push_back(b);
            adj[b].push_back(a);
            adjw[a].push_back(w);
            adjw[b].push_back(w);
            adjc[a].push_back(c);
            adjc[b].push_back(c);
        }
        vector<ll> difs[2];
        ll tts = 0;
        function<void(int,int)> dfs = [&](int u, int p){
            bool leaf = true;
            for(int i=0;i<adj[u].size();i++){
                int v = adj[u][i];
                ll w = adjw[u][i];
                int c = adjc[u][i] - 1;
                if(v != p){
                    leaf = false;
                    dfs(v, u);
                    cl[u] += cl[v];
                    tts += cl[v] * w;
                    ll aux = w;
                    while(aux){
                        ll dif = aux - aux/2;
                        difs[c].push_back(dif*cl[v]);
                        aux /= 2;
                    }
                }
            }
            if(leaf) cl[u] = 1;
        };
        dfs(1, 0);
        sort(difs[0].begin(), difs[0].end(), greater<ll>());
        sort(difs[1].begin(), difs[1].end(), greater<ll>());
        vector<vector<ll>> ps(2, vector<ll>(max(difs[0].size(), difs[1].size())+1, 0));
        for(int i=0;i<2;i++){
            for(int j=0;j<difs[i].size();j++){
                ps[i][j+1] = ps[i][j] + difs[i][j];
            }
        }
        ll ans = INF_INT;
        for(ll i=0;i<=difs[0].size();i++){
            ll lo = 0, hi = difs[1].size();
            ll tst = tts - ps[0][i] - ps[1][hi];
            if(tst > S) continue;
            while(lo != hi){
                ll mid = lo + (hi - lo ) / 2;
                ll tst = tts - ps[0][i] - ps[1][mid];
                if(tst <= S) hi = mid;
                else lo = mid + 1;
            }

            ans = min(ans, i + 2*lo);
        }
        cout << ans << "\n";
    }
}
