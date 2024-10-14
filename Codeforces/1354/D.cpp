#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;

// Segment Tree
int st[4*N], v[N];

void build(int p, int l, int r) {
  if (l == r) { st[p] = v[l]; return; }
  build(2*p, l, (l+r)/2);
  build(2*p+1, (l+r)/2+1, r);
  st[p] = st[2*p] + st[2*p+1]; // RMQ -> min/max, RSQ -> +
}

void update(int p, int l, int r, int i, int v) { // v = +1 
  if (r < i or l > i) return;
  if (l == i and r == i) { st[p]+=v; return; }
  update(2*p, l, (l+r)/2, i, v);
  update(2*p+1, (l+r)/2+1, r, i, v);
  st[p] = st[2*p] + st[2*p+1]; // RMQ -> min/max, RSQ -> +
}



int bin_search(int v){
    int p=1;
    int lo = 0;
    int hi = N-1;
    int qt=0;
    while(lo!=hi){
        if((qt+st[2*p])<v){
            qt += st[2*p];
            p = 2*p +1;
            
            lo = (lo+hi)/2 +1;
        }else{
            hi = (lo+hi)/2;
            p = 2*p;
        }
    }
    return lo;
}



int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
    int n,q;
    cin >> n >> q;
     for(int i=0;i<N;i++){
        v[i]=0;
    }
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        v[aux]++;
    }
    build(1,0,N-1);
    
    for(int i=0;i<q;i++){
        int aux;
        cin >> aux;
        if(aux<0){
            update(1,0,N-1,bin_search(abs(aux)),-1);
        }else{
            update(1,0,N-1,aux,1);
        }
    }
    if(bin_search(1)==(N-1)) cout << 0;
    else cout << bin_search(1);
}