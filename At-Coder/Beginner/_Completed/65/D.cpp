#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;   
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

struct Edge{
    int a, b, w;
    bool operator< (Edge v){
        return w < v.w;
    }
};

vector<Edge> edges;
vector<int> adj[N];
ll tw = 0;

void kruskal(){
    sort(edges.begin(), edges.end());
    init();
    for(auto e : edges){
        if(get(e.a) != get(e.b)){
            adj[e.a].push_back(e.b);
            adj[e.b].push_back(e.a);
            unite(e.a, e.b);
            tw += e.w;
        }
    }
}

bool cmp1(pair<pair<int,int>,int> p1, pair<pair<int,int>, int> p2){
    return make_pair(p1.first.second, p1.first.first) < make_pair(p2.first.second, p2.first.first);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<pair<int,int>, int>> vp(n+1);
    init();
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> vp[i].first.first >> vp[i].first.second;
        vp[i].second = i;
    }
    sort(vp.begin()+1, vp.end());
    for(int i=1;i<n;i++){
        edges.push_back({vp[i].second, vp[i+1].second, vp[i+1].first.first - vp[i].first.first});
    }
    sort(vp.begin()+1, vp.end(), cmp1);
    for(int i=1;i<n;i++){
        edges.push_back({vp[i].second, vp[i+1].second, vp[i+1].first.second - vp[i].first.second});
    }


    kruskal();
    cout << tw;
}   
