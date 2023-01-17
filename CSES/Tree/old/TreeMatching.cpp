
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+3, INF = 0x3f3f3f3f;
int h[N], n, m, par[N];
int st[4*N];

void build(int p, int l, int r) { //build(1,1,n)
  if (l == r) { st[p] = h[l]; return; }
  build(2*p, l, (l+r)/2);
  build(2*p+1, (l+r)/2+1, r);
  st[p] = max(st[2*p], st[2*p+1]); // RMQ -> min/max, RSQ -> +
}

int query(int p, int l, int r){
    if(l == r) return l;
    if(st[2*p] == st[1]) return query(2*p, l, (l+r)/2);
    else return query(2*p+1, (l+r)/2+1, r);

}

void update(int p, int l, int r, int i, int v) {
  if (r < i or l > i) return;
  if (l == i and r == i) { st[p] = v; return; }
  update(2*p, l, (l+r)/2, i, v);
  update(2*p+1, (l+r)/2+1, r, i, v);
  st[p] = max(st[2*p], st[2*p+1]); // RMQ -> min/max, RSQ -> +
}

vector<int> adj[N];

void dfs(int u, int p){
    h[u] = h[p]+1;
    par[u] = p;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v,u);

        }
    }
}





int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int cont = 0;
    cin >> n;
    for(int i=1; i<n; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    h[0]=-1;
    dfs(1,0);
    build(1,1,n);
    while(st[1] > 0){
        int aux = par[query(1,1,n)];
        for(auto v : adj[aux]){
            if(h[v] > h[aux])update(1,1,n,v,-1);
        }
        update(1,1,n,aux,-1);
        cont++;

    }

    cout << cont;

}

