#include <bits/stdc++.h>

using namespace std;
int n,m,q;
int mask = 0;
const int N = 300000;

// Segment Tree
long long int st[4*N], v[N];

void build(int p, int l, int r) { // build(1,0,n-1)
    if (l == r) { st[p] = v[l]; return; }
    build(2*p, l, (l+r)/2);
    build(2*p+1, (l+r)/2+1, r);
    st[p] = st[2*p] +  st[2*p+1]; // RMQ -> min/max, RSQ -> +
}

long long int query(int p, int l, int r, int i, int j){
    if (r < i or l > j) return 0;
    if (l >= i and r <= j) return st[p];
    return query(2*p, l, (l+r)/2, i, j) + query(2*p+1, (l+r)/2+1, r, i, j);
}

long long int query2(int p, int l, int r, int i, int j) { //query(1,0,n-1,a,b)
    if (r < i or l > j) return 0; // RMQ -> INF, RSQ -> 0
    if (l >= i and r <= j){ //now i will do it
        int k = r-l+1;
        int rm = mask - (mask % k);
        int ll = l  ^ rm, lr = r ^ rm;
        return st[p + (ll-l)/k];
    }
    return query2(2*p, l, (l+r)/2, i, j) + query2(2*p+1, (l+r)/2+1, r, i, j);
    // RMQ -> min/max, RSQ -> +
}

void update(int p, int l, int r, int i, int v) {
    if (r < i or l > i) return;
    if (l >= i and r <= i) { st[p] = v; return; }
    update(2*p, l, (l+r)/2, i, v);
    update(2*p+1, (l+r)/2+1, r, i, v);
    st[p] = st[2*p] + st[2*p+1]; // RMQ -> min/max, RSQ -> +
}

void replace(int x,int k){
    int pos = (x-1)^mask;
    update(1,0,m-1,pos,k);
}

void reverse(int k){
    mask = mask ^ ((1<<k) -1);
}
void swap(int k){
    mask = mask ^ (1<<k);
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);
    int a,b,c;
    cin >> n >> q;
    m = 1 << n;
    for(int i=0;i<m;i++){
        cin >> v[i];
    }
    build(1,0,m-1);

    for(int i=0;i<q;i++){
        cin >> a;
        if(a==1){
            cin >> b >> c;
            replace(b,c);
        }
        if(a==2){
            cin >> b;
            reverse(b);
        }
        if(a==3){
            cin >> b;
            swap(b);
        }
        if(a==4){
            cin >> b >> c;
            cout << query2(1,0,m-1,b-1,c-1) << "\n";
        }
    }


}