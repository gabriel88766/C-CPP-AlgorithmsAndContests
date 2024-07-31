#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
struct edge{
    ll u, v, w;
    bool operator< (const edge &e) const {
        return w < e.w;
    }
};

int p[N], sz[N];
bool ans[N];

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
    int n, m, q;
    cin >> n >> m >> q;
    vector<edge> eg;
    vector<pair<edge, int>> eq;
    for(int i=0;i<m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        eg.push_back({a, b, c});
    }
    for(int i=0;i<q;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        eq.push_back({{a, b, c}, i});
    }
    sort(eg.begin(), eg.end());
    sort(eq.begin(), eq.end());
    int p1 = 0, p2 = 0;
    while(p1 < m && p2 < q){
        if(eg[p1].w < eq[p2].first.w){
            unite(eg[p1].u, eg[p1].v);
            p1++;
        }else{
            if(get(eq[p2].first.u) != get(eq[p2].first.v)){
                ans[eq[p2].second] = 1;
            }else ans[eq[p2].second] = 0;
            p2++;
        }
    }
    //doesnt matter if only p1 < n
    while(p2 < q){
        if(get(eq[p2].first.u) != get(eq[p2].first.v)){
            ans[eq[p2].second] = 1;
        }else ans[eq[p2].second] = 0;
        p2++;
    }
    for(int i=0;i<q;i++){
        if(ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }
}
