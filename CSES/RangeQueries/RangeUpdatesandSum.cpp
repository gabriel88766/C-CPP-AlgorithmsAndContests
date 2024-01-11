#include <bits/stdc++.h>
 
using namespace std;
const int N = 2e5+3;
const long long int INF = 0x3f3f3f3f3f3f3f3f;
long long int st[4*N], v[N], lz[4*N], lm[4*N];
int mode,lastm = 0;
 
void build(int p,int l,int r){
    if(l == r){ st[p] = v[l]; return; }
    build(2*p,l,(l+r)/2);
    build(2*p+1,(l+r)/2+1,r);
    st[p] = st[2*p] + st[2*p+1];
}
 
void push(int p,int l,int r){
    if(lz[p]){
        if(lm[p] == 2){
            st[p] = (r-l+1)*lz[p];
            if(l!=r) lz[2*p] = lz[2*p+1] = lz[p], lm[2*p] = lm[2*p+1] = 2;
        }else{
            st[p] += (r-l+1)*lz[p];
            if(l!=r){
                lz[2*p] += lz[p];
                lz[2*p+1] += lz[p];
                if(!lm[2*p]) lm[2*p] = 1;
                if(!lm[2*p+1]) lm[2*p+1] = 1;
            }
        }
        lm[p]=0;
        lz[p] = 0;
    } 
}
 
void update(int p,int l,int r,int i,int j, int v){ //push, lazy propagation
    push(p,l,r);
    if(r < i || l > j) return;
    if(r <= j && i <= l){lm[p] = mode, lz[p] = v; push(p,l,r); return;}
    update(2*p, l, (l+r)/2, i, j, v);
    update(2*p+1, (l+r)/2+1, r, i, j, v);
    st[p] = st[2*p] + st[2*p+1];
}
 
long long int query(int p,int l,int r,int i,int j){
    push(p,l,r);
    if(r < i || l > j) return 0;
    if(r <= j && i <= l) return st[p];
    return query(2*p, l, (l+r)/2, i, j) + query(2*p+1, (l+r)/2+1, r, i, j);
}
 
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    build(1,1,n);
    for(int i=0;i<q;i++){
        int a,b,c;
        cin >> mode;
        if(mode==1){
            cin >> a >> b >> c;
            update(1,1,n,a,b,c);
        }else if(mode==2){
            cin >> a >> b >> c;
            update(1,1,n,a,b,c);
        }
        else{
            cin >> b >> c;
            cout << query(1,1,n,b,c) << "\n";
        }
    }
}
