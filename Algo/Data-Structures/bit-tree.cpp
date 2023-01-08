// a.k.a Fenwick Tree
// b & -b is the greatest power of 2 that divides b
// O(log n) query and update value
//tested https://cses.fi/problemset/task/1648/
const int N = 2e5+6;
 
ll bit[N];
ll v[N];
int n;
 
ll query(int b){ // sum in range [1, b]
    ll ans = 0;
    for(int i = b; i > 0; i -= i & -i){
        ans += bit[i];
    }
    return ans;
}
 
void add(int b, ll value){ //add value to position b
    for(int i = b; i <= n; i += i & -i){
        bit[i] += value;
    }
}
 
void build(){
    for(int i=1;i<=n;i++) add(i, v[i]);
}