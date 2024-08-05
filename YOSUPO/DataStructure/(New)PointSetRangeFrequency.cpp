#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//MergeSortTree high complexity first
const int N = 2e5+6;
map<int, int> st[4*N];
int v[N];
int n;


void build(int l = 1, int r = n, int p = 1){ //O(n log^2 n)
    if(l == r){ st[p].insert({v[l], 1}); return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2*p];
    for(auto [k, v] : st[2*p+1]) st[p][k] += v;
}

int query(int i, int j, int x, int l = 1, int r = n, int p = 1){ //O(log^2 n)
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l){
        if(st[p].count(x)) return st[p][x];
        else return 0; 
    }
    return query(i, j, x, l, (l + r)/2, 2 * p) + query(i, j, x, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

void update(int i, int val, int l = 1, int r = n, int p = 1){
    if(i < l || i > r) return;
    st[p][val]++;
    st[p][v[i]]--;
    if(st[p][v[i]] == 0){
        st[p].erase(v[i]);
    }
    if(l == r) {
        return;
    }
    update(i, val, l, (l + r)/2, 2 * p);
    update(i, val, (l + r)/2 + 1, r, 2 * p + 1);
    
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int  q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    if(n == 0) n = 1;
    else build();
    for(int i=0;i<q;i++){
        int t, k, val, l, r, x;
        cin >> t;
        if(t == 0){
            cin >> k >> val;
            update(k+1, val);
            v[k+1] = val;
        }else{
            cin >> l >> r >> x;
            cout << query(l+1, r, x) << "\n";
        }
    }
}
