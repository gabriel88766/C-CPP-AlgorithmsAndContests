#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+6;
ll pr[4*N], su[4*N], st[4*N], sum[4*N];
int v[N];
int n;

void build(int l = 1, int r = n, int p = 1){
    if(l == r){ pr[p] = su[p] = st[p] = sum[p] = v[l]; return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    pr[p] = max(pr[2*p], sum[2*p] + pr[2*p+1]);
    su[p] = max(su[2*p+1], su[2*p] + sum[2*p+1]);
    st[p] = max(st[2*p], max(st[2*p+1], su[2*p] + pr[2*p+1]));
    sum[p] = sum[2*p] + sum[2*p+1];
}

void update(int i, int value, int l = 1, int r = n, int p = 1){
    if(i < l || i > r) return;
    if(l == r) {pr[p] = su[p] = st[p] = sum[p] = value; return;}
    update(i, value, l, (l + r)/2, 2 * p);
    update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
    pr[p] = max(pr[2*p], sum[2*p] + pr[2*p+1]);
    su[p] = max(su[2*p+1], su[2*p] + sum[2*p+1]);
    st[p] = max(st[2*p], max(st[2*p+1], su[2*p] + pr[2*p+1]));
    sum[p] = sum[2*p] + sum[2*p+1];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    build();
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        update(a, b);
        cout << (st[1] > 0 ? st[1] : 0) << "\n";
    }
}   
