#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+6;
int stl[4*N], str[4*N];
int v[N];
int n;

void build(int l = 1, int r = n, int p = 1){
    if(l == r){ stl[p] = l; str[p] = n+1-l; return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    stl[p] = min(stl[2 * p], stl[2 * p + 1]); //some operation
    str[p] = min(str[2 * p], str[2 * p + 1]);
}

int query(int i, int j, int type, int l = 1, int r = n, int p = 1){
    if(j < l || i > r) return INF_INT; //identity element
    if(j >= r && i <= l){
        if(type == 1)  return stl[p];
        else  return str[p];
    }
    return min(query(i, j, type, l, (l + r)/2, 2 * p), query(i, j, type, (l + r)/2 + 1, r, 2 * p + 1)); //some operation
}

void update(int i, int value, int l = 1, int r = n, int p = 1){
    if(i < l || i > r) return;
    if(l == r) {stl[p] = value + l; str[p] = n+1-l + value; return;}
    update(i, value, l, (l + r)/2, 2 * p);
    update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
    stl[p] = min(stl[2 * p], stl[2 * p + 1]); //some operation
    str[p] = min(str[2 * p], str[2 * p + 1]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int q;
    cin >> n >> q;
    build();
    for(int i=1;i<=n;i++){
        cin >> v[i];
        update(i, v[i]);
    }
    for(int i=0;i<q;i++){
        int t, a, b;
        cin >> t;
        if(t == 1){
            cin >> a >> b;
            update(a, b);
        }else{
            cin >> a;
            int val1 = query(1, a, 2) - (n-a+1);
            int val2 = query(a, n, 1) - a;
            cout << min(val1,val2) << "\n";
        }

    }
}   
