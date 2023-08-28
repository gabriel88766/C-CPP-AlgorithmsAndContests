#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<ll> adj[N], adjd[N];
char vis[N];
ll val[N];

bool dfs(int i){
    bool ok = true;
    for(int j=0;j<adj[i].size();j++){
        if(!vis[adj[i][j]]){
            val[adj[i][j]] = val[i] + adjd[i][j];
            vis[adj[i][j]] = true;
            ok &= dfs(adj[i][j]); 
        }else{
            if(val[adj[i][j]] - val[i] != adjd[i][j]) ok = false;
        }
    }
    return ok;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<pair<ll,ll>,ll>> vp(m);
        for(int i=0;i<m;i++){
            int a,b,d;
            cin >> a >> b >> d;
            adj[a].push_back(b);
            adjd[a].push_back(d);
            adj[b].push_back(a);
            adjd[b].push_back(-d);
        }
        bool ok = true;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                val[i] = 0;
                vis[i] = true;
                ok &= dfs(i);
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";


        for(int i=1;i<=n;i++){
            adj[i].clear();
            adjd[i].clear();
            vis[i] = false;
            val[i] = 0;
        }
    }   
}
