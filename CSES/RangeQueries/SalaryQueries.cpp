#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int M = 18000000;
int st[M], lc[M], rc[M], cnt = 1; //216MB 
int v[200005];
int MAX_INT = 1e9;

void update(int pos, int add, int l = 1, int r = MAX_INT, int p = 1){
    if(l == r){ st[p] += add; return;}
    int mid = (l+r)/2;
    if(pos > mid){
        if(!rc[p]) rc[p] = ++cnt; 
        update(pos, add, mid+1, r, rc[p]);
    }else{
        if(!lc[p]) lc[p] = ++cnt;
        update(pos, add, l, mid, lc[p]);
    }
    st[p] = st[lc[p]] + st[rc[p]];
}

int query(int a, int b, int l = 1, int r = MAX_INT, int p = 1){
    if(p == 0) return 0; //node not created.
    if(b < l || a > r) return 0;
    if(l >= a && b >= r) return st[p];
    return query(a,b,l,(l+r)/2,lc[p]) + query(a,b,(l+r)/2+1,r,rc[p]);
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); 
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        update(v[i], 1);
    }
    for(int i=1;i<=q;i++){
        int a,b;
        char c;
        cin >> c >> a >> b;
        if(c == '?'){
            cout << query(a,b) << "\n";
        }else{
            update(v[a], -1);
            update(b, 1);
            v[a] = b;
        }
    }

}
