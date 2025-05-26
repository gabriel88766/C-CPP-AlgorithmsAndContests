#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 2e5+3, M = 20;   
int p[N], sz[N];
 
vector<pair<int,int>> rb;
void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ //log n
    return p[a] == a ? a : get(p[a]);
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
    rb.push_back({b, a});
}

void rollback(){
    if(rb.size() == 0){
        assert(false); //?? this may be a mistake.
        return;
    }
    auto [b, a] = rb.back();
    rb.pop_back();
    p[b] = b;
    sz[a] -= sz[b];
}
 
struct Edge{
    int a, b, w, j;
    bool operator< (Edge v){
        if(w != v.w) return w < v.w;
        else return make_pair(a,b) < make_pair(v.a,v.b);
    }
};
 
vector<Edge> edges;
char ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++) ans[i] = true;
    vector<tuple<int, int, int>> edg = {{0,0,0}};
    for(int i=1;i<=m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        edg.push_back({a, b, w});
        edges.push_back({a, b, w, i});
    }
    sort(edges.begin(), edges.end());
    vector<tuple<int, int, vector<int>>> allq; //first the w, then the query, then the set
    for(int i=1;i<=q;i++){
        int k;
        cin >> k;
        vector<pair<int, int>> vx;
        for(int j=0;j<k;j++){
            int x;
            cin >> x;
            vx.push_back({get<2>(edg[x]), x});
        }
        sort(vx.begin(), vx.end());
        int p = 0;
        while(p < vx.size()){
            int p2 = p;
            while(p2 + 1 < vx.size() && vx[p2+1].first == vx[p].first) p2++;
            //from p to p2; process
            vector<int> cs;
            for(int j=p;j<=p2;j++) cs.push_back(vx[j].second);
            allq.push_back({vx[p].first, i, cs});
            //end
            p = p2 + 1;
        }
    }
    sort(allq.begin(), allq.end());
    int p = 0;
    for(auto &[val, j, st] : allq){
        while(p < edges.size() && edges[p].w < val){
            unite(edges[p].a, edges[p].b);
            p++;
        }
        rb.clear(); //these added edges must not be rolled back
        for(auto &x : st){
            unite(get<0>(edg[x]), get<1>(edg[x]));
        }
        if(rb.size() != st.size()){
            ans[j] = false;
        }
        
        while(rb.size()){
            rollback();
        }
    }
    for(int i=1;i<=q;i++){
        if(ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
}
