//Segment tree on tree
#include<bits/stdc++.h>

using namespace std;

// Segment Tree Tested 1401F and 920F
// Dont need lazy if not updating in range. (Example 920F)
const int N = 2e5+3;
long long int st[4*N], v[N], u[N], act[N], sub[N];
long long int n,q,cont=1;


void build(int p, int l, int r) { //build(1,0,n-1)
  if (l == r) { st[p] = v[l]; return; }
  build(2*p, l, (l+r)/2);
  build(2*p+1, (l+r)/2+1, r);
  st[p] = st[2*p] + st[2*p+1]; // RMQ -> min/max, RSQ -> +
}



long long int query(int p, int l, int r, int i, int j) { //query(1,0,n-1,a,b)
  if (r < i or l > j) return 0; // RMQ -> INF, RSQ -> 0
  if (l >= i and r <= j) return st[p];
  return query(2*p, l, (l+r)/2, i, j) +
             query(2*p+1, (l+r)/2+1, r, i, j);
  // RMQ -> min/max, RSQ -> +
}

void update(int p, int l, int r, int i, long long int v) {
  if (r < i or l > i) return;
  if (l == i and r == i) { st[p] = v; return; }
  update(2*p, l, (l+r)/2, i, v);
  update(2*p+1, (l+r)/2+1, r, i, v);
  st[p] = st[2*p] + st[2*p+1]; // RMQ -> min/max, RSQ -> +
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
        cin >> u[i];
    }
    for(int i=2;i<=n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for(int i=1 ;i <= n;i++){
        v[act[i]] = u[i];
    }
    build(1,1,n);
    for(int i=1;i<=q;i++){
        int a,b,c;
        cin >> a;
        if(a==1){
           cin >> b >> c;
           update(1,1,n,act[b],c);
        }else{
            cin >> a;
            cout << query(1,1,n,act[a],act[a]+sub[a]-1) << "\n";
        }
    }
}
