#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


template<typename T, T (*op)(T, T), T (*nullel)()>
struct SegmentTree{
    vector<T> st;
    int n;
    SegmentTree(vector<T> &v){
        n = v.size();
        st.resize(4*n);
        build(v, 0, n-1, 1);
    }
    SegmentTree(ll sz){
        n = sz;
        st.resize(4*n);
    }
    void build(vector<T> &v, int l, int r, int p){
        if(l == r){st[p] = v[l]; return;}
        build(v, l, (l+r)/2, 2*p);
        build(v, (l+r)/2+1, r, 2*p+1);
        st[p] = op(st[2*p], st[2*p+1]);
    }
    T query(int i, int j, int l, int r, int p){
        if(j < l || i > r) return nullel(); 
        if(j >= r && i <= l) return st[p];
        return op(query(i, j, l, (l + r)/2, 2 * p), query(i, j, (l + r)/2 + 1, r, 2 * p + 1)); 
    }
    T query(int i, int j){
        return query(i, j, 0, n-1, 1);
    }
    void update(int i, T value, int l, int r, int p){
        if(i < l || i > r) return;
        if(l == r) {st[p] = value; return;}
        update(i, value, l, (l + r)/2, 2 * p);
        update(i, value, (l + r)/2 + 1, r, 2 * p + 1);
        st[p] = op(st[2 * p], st[2 * p + 1]); //some operation
    }
    void update(int i, T value){
        update(i, value, 0, n-1, 1);
    }
    int find(int l, int r, int p, int val){ //segtree op must be sum.
        if(l == r) return l;
        int m = (l + r)/2;
        if(st[2*p] > val) return find(m+1, r, 2*p+1, val);
        else return find(l, m, 2*p, val);
    }
    int find(int val){
        return find(0, n-1, 1, val);
    }
};

int op(int a, int b){
    return min(a, b);
}

int el(){
    return INF_INT;
}

const int N = 3000005;
int id[N];
int par[N];
int aa[N], ad[N];
vector<int> adj[N];
SegmentTree<int, op, el> st1(1);
int cur;

int p[N];
set<pair<int,int>> st[N];
map<int, int> mp2[N];
void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i;  st[i] = {{1, id[i]}}; mp2[i].clear(); mp2[i][id[i]] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(st[a].size() < st[b].size()) swap(a,b);
    p[b] = a;
    for(auto [qt, id] : st[b]){
        int cur = mp2[a][id];
        if(cur != 0) st[a].erase({cur, id});
        mp2[a][id] += qt;
        st[a].insert({mp2[a][id], id});
    }
}


void solve(int u, int p){
    //for ancestor
    int ca = st1.query(1, cur);
    if(ca == INF_INT){
        aa[u] = 0;
    }else{
        //find the first 
        aa[u] = st1.find(ca);
    }
    int cv = st1.query(id[u], id[u]);
    if(cv == INF_INT) st1.update(id[u], 1);
    else st1.update(id[u], cv + 1);
    for(auto v : adj[u]){
        solve(v, u);
    }
    for(auto v : adj[u]){
        unite(adj[u][0], v);
    }
    if(adj[u].size()){
        int vc = get(adj[u][0]);
        ad[u] = st[vc].begin()->second;
        unite(adj[u][0], u);
    }else ad[u] = 0;
    st1.update(id[u], cv);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("least_common_ancestor_input.txt", "r", stdin); //test input
    freopen("out.txt", "w", stdout); //test input
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int n;
        cin >> n;
        vector<string> name(n+1);
        vector<string> alln;
        for(int i=1;i<=n;i++){
            cin >> par[i] >> name[i];
            alln.push_back(name[i]);
        }
        sort(alln.begin(), alln.end());
        alln.resize(unique(alln.begin(), alln.end()) - alln.begin());
        cur = 0;
        map<string, int> mp;
        for(auto x : alln){
            mp[x] = ++cur;
        }
        for(int i=1;i<=n;i++){
            id[i] = mp[name[i]];
            if(par[i] != -1){
                adj[par[i]].push_back(i);
            }
        }
        st1 = SegmentTree<int, op, el>(cur+1);
        for(int i=0;i<=cur;i++){
            st1.update(i, INF_INT);
        }
        init(n);
        solve(1, 0);
        ll hash = 0;
        for(int i=1;i<=n;i++){
            hash = hash * (cur + 1) + aa[i];
            hash %= MOD;
            hash = hash * (cur + 1) + ad[i];
            hash %= MOD;
        }
        cout << "Case #" << i << ": " << hash << endl;

        //clear
        mp.clear();
        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
    }
}
