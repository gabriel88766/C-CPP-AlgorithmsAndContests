#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 1e5+6;
vector<vector<vector<ll>>> st(4*N, vector<vector<ll>> (2, vector<ll> (2)));
vector<vector<vector<ll>>> v(N, vector<vector<ll>> (2, vector<ll> (2)));
vector<vector<ll>> retmul(2, vector<ll> (2));
vector<vector<ll>> idt = {{1, 0}, {0, 1}};
ll n, m;

void mul(vector<vector<ll>> u, vector<vector<ll>> v){
    retmul[0][0] = (u[0][0] * v[0][0] + u[0][1] * v[1][0]) % m;
    retmul[0][1] = (u[0][0] * v[0][1] + u[0][1] * v[1][1]) % m;
    retmul[1][0] = (u[1][0] * v[0][0] + u[1][1] * v[1][0]) % m;
    retmul[1][1] = (u[1][0] * v[0][1] + u[1][1] * v[1][1]) % m;
}

void build(int l = 1, int r = n, int node = 1){
    if(l == r){ st[node] = v[l]; return; }
    build(l, (l+r)/2, 2 * node);
    build((l+r)/2 + 1, r, 2 * node + 1);
    mul(st[2 * node], st[2 * node +1]);
    st[node] = retmul;
}

void query(vector<vector<ll>> &v, int i, int j, int l = 1, int r = n, int node = 1){
    if(j < l || i > r){
        v = idt;
        return;
    } //identity element
    if(j >= r && i <= l){
        v = st[node];
        return;
    }
    mul(query(i, j, l, (l + r)/2, 2 * node), query(i, j, (l + r)/2 + 1, r, 2 * node + 1));
    return retmul;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int q;
    cin >> m >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> v[i][0][0] >> v[i][0][1] >> v[i][1][0] >> v[i][1][1];
    }
    build();
    while(q--){
        int a,b,c;
        cin >> a >> b;
        vector<vector<ll>> ans = query(a,b);
        cout << ans[0][0] << " " << ans[0][1] << "\n";
        cout << ans[1][0] << " " << ans[1][1] << "\n\n";
    }
}
