#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N], qnt[N];

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
    qnt[a] += qnt[b];
}

//unite by y
int lsy[N];
set<int> ally[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n;
    cin >> n;
    vector<pair<int, int>> vx;
    for(int i=1;i<=n;i++){
        int x, y;
        cin >> x >> y;
        vx.push_back({x, y});
        if(lsy[y]){
            unite(x, lsy[y]);
        }
        qnt[get(x)]++;
        lsy[y] = x;
    }
    for(auto [x, y] : vx){
        ally[get(x)].insert(y);
    }
    set<int> vis;
    ll ans = 0;
    for(int i=1;i<N;i++){
        if(!vis.count(get(i))){
            vis.insert(get(i));
            ll cur = sz[get(i)];
            cur *= ally[get(i)].size();
            cur -= qnt[get(i)];
            ans += cur;
        }
    }
    cout << ans << "\n";
}
