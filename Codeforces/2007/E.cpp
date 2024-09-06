#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+2;
vector<int> adj[N], chk[N];
int h[N], par[N], in[N], cnt[N];

void dfs(int u, int p){
    h[u] = h[p] + 1;
    par[u] = p;
    for(auto v : adj[u]) dfs(v, u);
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
        ll w;
        cin >> n >> w;
        for(int i=2;i<=n;i++){
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
        h[0] = -1;
        dfs(1, 0);
        for(int i=2;i<=n;i++) in[i] = true;
        int cc = 0;
        for(int i=1;i<=n;i++){
            vector<int> cur;
            int a = i;
            int b = ((i%n) + 1);
            if(h[a] < h[b]) swap(a, b);
            while(h[a] != h[b]){
                cur.push_back(a);
                a = par[a];
            }
            while(a != b){
                cur.push_back(a);
                cur.push_back(b);
                a = par[a];
                b = par[b];
            }
            cc += cur.size();
            cnt[i] = cur.size();
            for(auto x : cur){
                chk[x].push_back(i);
            }
        }
        ll s = 0, ttu = n;
        cc = 0;
        for(int i=2;i<=n;i++){
            int x;
            ll val;
            cin >> x >> val;
            s += val;
            in[x] = false;
            for(auto y : chk[x]){
                cnt[y]--;
                if(!cnt[y]) ttu--;
            }
            cout << 2*s + ttu*(w-s) << " ";
        }
        cout << "\n";
        for(int i=1;i<=n;i++){
            adj[i].clear();
            chk[i].clear();
        }
    }
}
