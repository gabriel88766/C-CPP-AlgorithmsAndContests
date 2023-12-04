#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+6;
ll st[4*N];
ll ps[N];
ll v[N];
int n;

pair<ll,ll> query(int i, ll psx, int l = 0, int r = n, int p = 1){
    if(l == r) return {ps[l] - ps, ps[l] - psx};
    int m = (l + r) / 2;
    int m1 = m+1;
    if(m1 > i) return query(i, psx, l, m, 2*p);
    else{
        
    } 
    if(j < l || i > r) return 0; //identity element
    if(j >= r && i <= l) return st[p];
    return query(i, j, l, (l + r)/2, 2 * p) + query(i, j, (l + r)/2 + 1, r, 2 * p + 1); //some operation
}

void update(int i, ll value, int l = 0, int r = n, int p = 1){
    if(i < l || i > r) return;
    if(l == r) {st[p] = value; return;}
    update(i, value, l, (l + r)/2, 2 * p);
    update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1]; //some operation
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        ps[i] = ps[i-1] + v[i];
    }
    for(int i=1;i<=n;i++){

    }
}
