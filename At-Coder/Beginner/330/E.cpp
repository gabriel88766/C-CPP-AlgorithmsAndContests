#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+6;
ll st[4*N];
ll v[N];
int n;

ll query(int l = 0, int r = n, int p = 1){
    if(l == r) return l;
    if(st[2*p] == 0) return query(l, (l+r)/2, 2*p);
    else return query((l+r)/2+1, r, 2*p+1);
}

void update(int i, int value, int l = 0, int r = n, int p = 1){
    if(i < l || i > r) return;
    if(l == r) {st[p] += value; return;}
    update(i, value, l, (l + r)/2, 2 * p);
    update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = min(st[2 * p], st[2 * p + 1]); //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m, q;
    cin >> m >> q;
    n = m + 2;
    for(int i = 1; i<= m; i++){
        cin >> v[i];
        update(v[i], 1);
    }
    for(int i=0;i<q;i++){
        int ind, x;
        cin >> ind >> x;
        update(v[ind], -1);
        v[ind] = x;
        update(v[ind], 1);
        cout << query() << "\n";
    }
}
