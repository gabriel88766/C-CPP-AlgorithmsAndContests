#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 2e5+3;
int n, k1, k2;
ll ans = 0;
basic_string<int> tree[N]; 
char ac[N];
int sub[N];
int sz[N];
int d[N];
int qt[N];
int alld[N];
int pp = 0; 
 
int bit[N];
 
int query(int b){ // sum in range [1, b]
    int ans = 0;
    for(int i = b; i > 0; i -= i & -i){
        ans += bit[i];
    }
    return ans;
}
 
void add(int b, int value){ //add value to position b
    for(int i = b; i <= n; i += i & -i){
        bit[i] += value;
    }
}
 
  
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
    memset(ac, 0, sizeof(ac));
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
                    int l = k1-x;
                    int r = k2-x;
                    if(r < 0) continue;
                    ans += query(r);
                    if(l <= 0) ans++;
                    else ans -= query(l-1);
                }
                for(int i=0;i<pp;i++){
                    auto x = alld[i];
                    add(x, 1);
                    qt[x]++;
                }
                
            }
        }
        for(int i=1;i<=sz[u];i++) add(i, -qt[i]);
    }
}
 
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> k1 >> k2;
    //c.tree.resize(n+1);
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    solve();
    cout << ans << "\n";
}
