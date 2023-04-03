#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+3;
ll st[4*N];
int n;

int calc(int b){
    int maxi = 0, mini = 9;
    while(b){
        int c = b % 10;
        maxi = max(maxi, c);
        mini = min(mini, c);
        b /= 10;
    }
    return maxi - mini;
}


int combine(int a, int b){
    if(calc(a) > calc(b)) return a;
    else return b;
}

void build(int l = 1, int r = n, int p = 1){
    if(l == r){ st[p] = l; return; }
    build(l, (l+r)/2, 2 * p);
    build((l+r)/2 + 1, r, 2 * p + 1);
    st[p] = combine(st[2 * p], st[2 * p + 1]); //some operation
}

ll query(int i, int j, int l = 1, int r = n, int p = 1){
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return combine(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); //some operation
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    n = 1000000;
    build();
    while(t--){
        int l, r;
        cin >> l >> r;
        if(l == r) cout << l << "\n";
        else cout << query(l, r) << "\n";
    }
}
