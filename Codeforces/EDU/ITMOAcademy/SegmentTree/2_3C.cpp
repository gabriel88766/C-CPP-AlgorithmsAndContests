#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 2e5+6;
ll st[4*N], lz[4*N];
ll v[N];
int n;
 
void push(int l, int r, int p){
    if(lz[p]){ //0 can be assigned? change!
        st[p] += lz[p]; 
        if(l != r){
            lz[2 * p] += lz[p]; // += increment = update
            lz[2 * p + 1] += lz[p];
        } 
        lz[p] = 0;
    }
}

int query(int i, ll y, int l = 0, int r = n-1, int p = 1){
    push(l, r, p);
    if(i > r) return INF_INT;
    if(l == r){
        if(st[p] >= y) return l;
        else return INF_INT;
    }
    push(l, (l+r)/2, 2*p);
    push((l+r)/2+1, r, 2*p+1);
    int ans = INF_INT;
    if(st[2*p] >= y){
        int ans = query(i, y, l, (l + r)/2, 2 * p);
        if(ans != INF_INT) return ans;
        else return query(i, y, (l + r)/2 + 1, r, 2 * p + 1);
    }else if(st[2*p+1] >= y){
        return query(i, y, (l + r)/2 + 1, r, 2 * p + 1);
    }else return INF_INT;
}

ll query2(int i, int j, int l = 0, int r = n-1, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return max(query2(i, j, l, (l + r)/2, 2 * p), query2(i, j, (l + r)/2 + 1, r, 2 * p + 1)); //some operation
}   
 
void update(int i, int j, ll value, int l = 0, int r = n-1, int p = 1){
    push(l, r, p);
    if(j < l || i > r) return;
    if(l >= i && r <= j) {lz[p] = value; push(l, r, p); return;}
    update(i, j, value, l, (l + r)/2, 2 * p);
    update(i, j, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = max(st[2*p], st[2*p+1]);
}
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> n >> q;
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        if(t == 1){
            int l, r, v;
            cin >> l >> r >> v;
            update(l, r-1, v);
        }else{
            int x, l;   
            cin >> x >> l;
            //for(int j=n/2;j>=1;j>>=1){
            //    while(l+j < n && query2(l, l+j-1) < x) l += j;
            //}
            //if(query2(l,l) >= x) cout << l << "\n";
            //else cout << "-1\n";

            int k = query(l, x);
            if(k == INF_INT) cout << "-1\n";
            else cout << k << "\n";
        }
    }
}