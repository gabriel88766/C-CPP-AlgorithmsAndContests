#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Edge{
    int a, b;
    ll w;
    bool operator< (Edge e){
        return w < e.w;
    }
};

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
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    init();
    vector<Edge> v;
    vector<pair<ll,int>> vp;
    for(int i=1;i<=n;i++){
        ll w;
        cin >> w;
        vp.push_back({w, i});
    }
    sort(vp.begin(), vp.end());
    for(int i=0;i<m;i++){
        int a,b;
        ll w;
        cin >> a >> b >> w;
        v.push_back({a,b,w});
    }
    sort(v.begin(), v.end());
    int bp = 0, p2 = 1;
    ll ans = 0;
    for(int i=1;i<n;i++){
        //add edge...
        while(get(vp[0].second) == get(vp[p2].second)) p2++;
        while(bp < m && get(v[bp].a) == get(v[bp].b)) bp++;
        ll c1, c2;
        if(bp < m) c1 = v[bp].w;
        else c1 = INF_LL;
        c2 = vp[0].first + vp[p2].first;
        if(c1 > c2){
            ans += c2;
            unite(vp[0].second, vp[p2].second);
        }else{
            ans += c1;
            unite(v[bp].a, v[bp].b);
        }
     }
     cout << ans;
}
 