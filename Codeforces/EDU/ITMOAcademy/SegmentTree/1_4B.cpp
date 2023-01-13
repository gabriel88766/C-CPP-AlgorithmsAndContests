#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

int mod;

struct Matrix{
    int a,b,c,d;
    Matrix operator*(const Matrix &m){
        Matrix result;
        result.a = (a*m.a + b*m.c)%mod;
        result.b = (a*m.b + b*m.d)%mod;
        result.c = (c*m.a + d*m.c)%mod;
        result.d = (c*m.b + d*m.d)%mod;
        return result;
    }
};

const int N = 2e5+6;
Matrix st[4*N];
Matrix v[N];
Matrix idt = {1,0,0,1};
int n;




void build(int l = 1, int r = n, int node = 1){
    if(l == r){ st[node] = v[l]; return; }
    build(l, (l+r)/2, 2 * node);
    build((l+r)/2 + 1, r, 2 * node + 1);
    st[node] = st[2 * node] * st[2 * node +1];
}

Matrix query( int i, int j, int l = 1, int r = n, int node = 1){
    if(j < l || i > r){
        return idt;
    } //identity element
    if(j >= r && i <= l){
        return st[node];
    }
    return query(i, j, l, (l + r)/2, 2 * node) * query(i, j, (l + r)/2 + 1, r, 2 * node + 1);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int q;
    cin >> mod >> n >> q;
    for(int i=1;i<=n;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v[i].a = a % mod;
        v[i].b = b % mod;
        v[i].c = c % mod;
        v[i].d = d % mod;
    }
    build();
    while(q--){
        int a,b,c;
        cin >> a >> b;
        Matrix ans = query(a,b);
        cout << ans.a << " " << ans.b << "\n";
        cout << ans.c << " " << ans.d << "\n\n";
    }
}
