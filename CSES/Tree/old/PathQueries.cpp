//Segment tree on tree
#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+3;
long long st[4*N], lz[4*N];
int v[N], act[N], sub[N];
int n,q,cont=1;

void push(int p,int l,int r){
    if(lz[p]){
        st[p] += lz[p];
        if(l!=r) {lz[2*p+1] += lz[p]; lz[2*p] += lz[p]; }
        lz[p] = 0;
    }
}
long long int query(int p, int l, int r, int i, int j) {
  push(p,l,r);
  if (r < i or l > j) return 0;
  if (l >= i and r <= j) return st[p];
  return query(2*p, l, (l+r)/2, i, j) +
             query(2*p+1, (l+r)/2+1, r, i, j);

}
void update(int p, int l, int r, int i, int j, long long int v) {
  push(p,l,r);
  if (r < i or l > j) return;
  if (l >= i and r <= j) { lz[p] = v, push(p,l,r); return; }
  update(2*p, l, (l+r)/2, i, j, v);
  update(2*p+1, (l+r)/2+1, r, i, j, v);
  st[p] = st[2*p] + st[2*p+1];
}

vector<int> adj[N];

void dfs(int x,int p=-1) {
  act[x] = cont++;
  sub[x] = 1;
  for (int v : adj[x]) if (v!=p)
    dfs(v,x);
  sub[p] += sub[x];
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for(int i=1 ;i <= n;i++){
        cin >> v[i];
    }
    for(int i=2;i<=n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for(int i=1 ;i <= n;i++){
        update(1,1,n,act[i],act[i]+sub[i]-1, v[i]);
    }

    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a;
        if(a==1){
           cin >> a >> b;
           long long int val = b-v[a];
           v[a] = b;
           update(1,1,n,act[a],act[a]+sub[a]-1,val);
        }else{
            cin >> a;
            cout << query(1,1,n,act[a],act[a]) << "\n";
        }
    }
}
