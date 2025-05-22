#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];

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
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n;
    cin >> n;
    vector<tuple<int, int, int>> vt(n-1);
    for(int i=0;i<n-1;i++){
        int a, b, v;
        cin >> a >> b >> v;
        vt[i] = {v, a, b};
    }
    sort(vt.begin(), vt.end(), greater<tuple<int, int, int>>());
    ll ans = 0;
    for(auto &[v, a, b] : vt){
        a = get(a);
        b = get(b);
        ll tt = sz[a];
        tt *= sz[b];
        tt *= v;
        ans += tt;
        unite(a, b);
    }
    cout << ans << "\n";
}
