#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 505;   
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


ll binpow(ll a, ll b, ll m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    init();
    vector<tuple<int, int, int>> edg;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int w = binpow(v[i], v[j], m) + binpow(v[j], v[i], m);
            w %= m;
            edg.push_back({w, i, j});
        }   
    }
    sort(edg.begin(), edg.end(), greater<tuple<int,int,int>>());
    ll ans = 0;
    for(auto [w, a, b] : edg){
        if(get(a) != get(b)){
            ans += w;
            unite(a, b);
        }
    }
    cout << ans << "\n";
}
