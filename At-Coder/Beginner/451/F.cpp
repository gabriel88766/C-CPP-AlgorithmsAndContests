#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N], inv[N], qt[N];
int ans = 0;

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

pair<int, int> get(int a, int val = 0){ 
    return p[a] == a ? make_pair(a, val ^ inv[a]) : get(p[a], val ^ inv[a]);
}

void unite(int u, int v){
    pair<int, int> a = get(u);
    pair<int, int> b = get(v);
    if(a.first == b.first) return;
    if(sz[a.first] < sz[b.first]) swap(a,b);
    if(a.second == b.second){
        int d1 = sz[a.first] - 2 * qt[a.first];
        int d2 = sz[b.first] - 2 * qt[b.first];
        qt[a.first] = qt[a.first] + qt[b.first] + min(d1,d2);
        ans += min(d1, d2);
        if(d1 < d2){
            inv[a.first] ^= 1;
            inv[b.first] ^= 1;
        }else{
            inv[b.first] ^= 1;
        }
    }else{
        qt[a.first] += qt[b.first];
    }
    p[b.first] = a.first;
    sz[a.first] += sz[b.first];
}



//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, q;
    cin >> n >> q;
    
    for(int xxx=1;xxx<=q;xxx++){
        int u, v;
        cin >> u >> v;
        auto a = get(u), b = get(v);
        if(ans == -1 || (a.first == b.first && a.second == b.second)) ans = -1;
        else{
            unite(u, v);
        }
        cout << ans << "\n";
    }
}
