#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+6;
int st[4*N], lz[4*N];
int v[N];
int n;

void build(int l = 1, int r = n, int node = 1){
    if(l == r){ st[node] = v[l]; return; }
    build(l, (l+r)/2, 2 * node);
    build((l+r)/2 + 1, r, 2 * node + 1);
    st[node] = min(st[2 * node], st[2 * node + 1]); //some operation
}

void push(int l, int r, int node){
    if(lz[node]){ //0 can be assigned? change!
        st[node] += lz[node]; //RMQ = lz, RSQ, = (r-l+1)*lz
        if(l != r){
            lz[2 * node] += lz[node]; // += increment = update
            lz[2 * node + 1] += lz[node];
        } 
        lz[node] = 0;
    }
}

ll query(int i, int j, int l = 1, int r = n, int node = 1){
    push(l, r, node);
    if(j < l || i > r) return INF_INT; //identity element
    if(j >= r && i <= l) return st[node];
    return min(query(i, j, l, (l + r)/2, 2 * node), query(i, j, (l + r)/2 + 1, r, 2 * node + 1)); //some operation
}

void update(int i, int j, ll value, int l = 1, int r = n, int node = 1){
    push(l, r, node);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[node] = value; push(l, r, node); return;}
    update(i, j, value, l, (l + r)/2, 2 * node);
    update(i, j, value, (l + r)/2 + 1, r, 2 * node + 1);
    st[node] = min(st[2 * node], st[2 * node + 1]); //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int cnt =0 ;
    string s;
    cin >> n >> s;
    v[0] = 0;
    for(int i=1;i<=n;i++){
        if(s[i-1] == '(') v[i] = v[i-1] + 1;
        else v[i] = v[i-1] - 1;
    }
    build();
    for(int i=1;i<=n;i++){
        if(s[i-1] == '('){
            update(i, n, -2);
            if(query(1,n) == 0 && query(n,n) == 0) cnt++;
            update(i, n, 2);
        }else{
            update(i, n, 2);
            if(query(1,n) == 0 && query(n,n) == 0) cnt++;
            update(i, n, -2);
        }
    }
    cout << cnt;
    
    
}
 