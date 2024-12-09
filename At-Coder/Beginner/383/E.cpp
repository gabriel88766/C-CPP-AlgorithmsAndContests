#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N], ta[N], tb[N];
void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
    ta[a] += ta[b];
    tb[a] += tb[b];
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<int,int,int>> vt(m);

    for(int i=0;i<m;i++){
        int u, v, x;
        cin >> u >> v >> x;
        vt[i] = {x, u, v};
    }
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        ta[x]++;
    }
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        tb[x]++;
    }
    sort(vt.begin(), vt.end());
    ll ans = 0;
    for(auto [x, u, v] : vt){
        unite(u, v);
        ll y = min(ta[get(u)], tb[get(u)]);
        ans += y * x;
        ta[get(u)] -= y;
        tb[get(u)] -= y;
    }
    cout << ans << "\n";

}
