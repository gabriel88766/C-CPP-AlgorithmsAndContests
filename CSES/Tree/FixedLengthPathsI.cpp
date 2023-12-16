#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 2e5+3;
int n, k;
ll ans = 0;
vector<char> ac(N);
vector<int> sub(N);
vector<vector<int>> tree(N); //old tree
vector<int> sz(N);
vector<int> d(N);
vector<int> qt(N);
vector<int> alld(N);
int pp = 0; 

struct centroid{    
    void dfsT(int u, int p){
        alld[pp++] = d[u];
        sub[u] = 1;
        for(auto v : tree[u]){
            if(v != p && !ac[v]){
                d[v] = d[u] + 1;
                dfsT(v, u);
                sub[u] += sub[v];
            }
        }
    }
    int find_centroid(int u){
        dfsT(u, 0);
        int sz = sub[u]/2, p = 0;
        while(true){
            int nxt = 0;
            for(auto v: tree[u]){
                if(!ac[v] && sub[v] > sz && v != p){
                    nxt = v;
                }
            }
            if(nxt){
                p = u;
                u = nxt;
            }else break;
        }
        return u;
    }
    void solve(){
        ac.assign(tree.size(), false);
        qt[0] = 1;
        int rt = find_centroid(1);
        ac[rt] = true;
        queue<int> q;
        q.push(rt);
        sz[rt] = sub[rt];
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(int i=1;i<=sz[u];i++) qt[i] = 0;
            for(auto v : tree[u]){
                if(!ac[v]){
                    d[v] = 1;
                    pp = 0;
                    int t = find_centroid(v);
                    ac[t] = true;
                    sz[t] = sub[t];
                    q.push(t);
                    for(int i=0;i<pp;i++){
                        auto x = alld[i];
                        if(k-x >= 0 && k-x <= sz[u]) ans += qt[k-x];
                    }
                    for(int i=0;i<pp;i++){
                        auto x = alld[i];
                        qt[x]++;
                    }
                    
                }
            }
        }
    }
};
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in", "r", stdin); //test input
    cin >> n >> k;
    centroid c;
    //c.tree.resize(n+1);
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    c.solve();
    cout << ans << "\n";
} 