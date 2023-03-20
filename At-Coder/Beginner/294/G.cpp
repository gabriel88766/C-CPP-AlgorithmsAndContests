//Segment tree on tree
#include<bits/stdc++.h>
 
typedef long long int ll;
using namespace std;
 
const ll N = 2e5+3, M = 20;
long long st[4*N], lz[4*N];
ll v[N], act[N], sub[N], par[N];
ll n,q,cont=1;
 
void push(ll p,ll l,ll r){
    if(lz[p]){
        st[p] += lz[p];
        if(l!=r) {lz[2*p+1] += lz[p]; lz[2*p] += lz[p]; }
        lz[p] = 0;
    }
}

ll query(ll p, ll l, ll r, ll i, ll j) {
  push(p,l,r);
  if (r < i or l > j) return 0;
  if (l >= i and r <= j) return st[p];
  return query(2*p, l, (l+r)/2, i, j) + query(2*p+1, (l+r)/2+1, r, i, j);
}
void update(ll p, ll l, ll r, ll i, ll j, ll v) {
    push(p,l,r);
    if (r < i or l > j) return;
    if (l >= i and r <= j) { lz[p] = v, push(p,l,r); return; }
    update(2*p, l, (l+r)/2, i, j, v);
    update(2*p+1, (l+r)/2+1, r, i, j, v);
    st[p] = st[2*p] + st[2*p+1];
}
 
vector<ll> adj[N], adjw[N];
 
void dfs(ll u,ll p=-1) {
    act[u] = cont++;
    sub[u] = 1;
    for (ll i=0;i<adj[u].size(); i++){
        ll x = adj[u][i];
        if (x!=p){
            v[x] = adjw[u][i];
            par[x] = u;
            dfs(x,u);
            sub[u] += sub[x];
        } 
    }
}
 
ll rt = 1, anc[N][M], h[N];

void dfs_2(ll u, ll par){ 
    anc[u][0] = par;
    h[u] = h[par] + 1;
    for(auto x : adj[u]){
        if(x != par){
            dfs_2(x, u);
        }
    } 
}

void build(ll n){
    h[0] = -1;
    dfs_2(rt, 0);
    for(ll j = 1; j < M; j++){
        for(ll i = 1; i <= n; i ++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
}

ll lca(ll a, ll b){ 
    if(h[a] > h[b]) swap(a, b);
    ll diff = h[b] - h[a];
    for(ll i = M-1; i>=0;i--) if(diff & (1 << i)) b = anc[b][i];
    if(a == b) return a;
    for(ll i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
    }
    return anc[a][0];
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    vector<pair<ll, pair<ll,ll>>> edgs;
    for(ll i=2;i<=n;i++){
        ll a,b, c;
        cin >> a >> b >> c;
        adj[a].push_back(b);
        adjw[a].push_back(c);
        adj[b].push_back(a);
        adjw[b].push_back(c);
        edgs.push_back({c, {a,b}});
    }
    dfs(1);
    build(n);
    for(ll i=1 ;i <= n;i++){
        update(1,1,n,act[i],act[i]+sub[i]-1, v[i]);
    }
    cin >> q;
 
    for(ll i=1;i<=q;i++){
        ll a, b;
        cin >> a;
        if(a==1){
           cin >> a >> b;
           a--;
           ll u = edgs[a].second.first;
           ll v = edgs[a].second.second;
           ll val = b-edgs[a].first;
           edgs[a].first = b;
           if(par[u] == v){
                update(1,1,n,act[u],act[u]+sub[u]-1,val);
           }else{
                update(1,1,n,act[v],act[v]+sub[v]-1,val);
           }
        }else{
            cin >> a >> b;
            ll c = lca(a, b);
            cout << query(1,1,n,act[a],act[a]) + query(1,1,n,act[b],act[b]) - 2 * query(1,1,n,act[c],act[c])<< "\n";
        }
    }
}