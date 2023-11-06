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
        vector<vector<ll>> adj(n+1), adjw(n+1);
        vector<ll> cl(n+1); 
        for(int i=1;i<n;i++){
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back(b);
            adj[b].push_back(a);
            adjw[a].push_back(w);
            adjw[b].push_back(w);
        }
        vector<ll> difs;
        ll tts = 0;
        function<void(int,int)> dfs = [&](int u, int p){
            bool leaf = true;
            for(int i=0;i<adj[u].size();i++){
                int v = adj[u][i];
                ll w = adjw[u][i];
                if(v != p){
                    leaf = false;
                    dfs(v, u);
                    cl[u] += cl[v];
                    tts += cl[v] * w;
                    ll aux = w;
                    while(aux){
                        ll dif = aux - aux/2;
                        difs.push_back(dif*cl[v]);
                        aux /= 2;
                    }
                }
            }
            if(leaf) cl[u] = 1;
        };
        dfs(1, 0);
        sort(difs.begin(), difs.end(), greater<ll>());
        int p = 0;
        while(tts > S){
            tts -= difs[p++];
        }
        cout << p << "\n";
    }
}
