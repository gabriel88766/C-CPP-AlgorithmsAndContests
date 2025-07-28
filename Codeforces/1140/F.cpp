#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 3e5+3;
ll ans[N], cur = 0;

ll p[N], sz[N], val[N];
stack<tuple<int, int, int>> rb;

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
    ll od = sz[a] * val[a] + sz[b] * val[b];
    sz[a] += sz[b];
    val[a] += val[b];
    ll nw = sz[a] * val[a];
    cur += nw - od;
    rb.push({2, a, b});
}

vector<int> ap[N]; 

void rollback(){
    if(rb.size() == 0){
        assert(false); //?? this may be a mistake.
        return;
    }
    auto [a, b, c] = rb.top();
    rb.pop();
    if(a == 1){
        ap[c].pop_back();
        if(b != 0){
            cur -= sz[b];
            val[b]--;
        }
    }else{
        ll od = sz[b] * val[b];
        p[c] = c;
        sz[b] -= sz[c];
        val[b] -= val[c];
        ll nw = sz[b] * val[b] + sz[c] * val[c];
        cur += nw - od;
    }
    // 
}

void add_point(pair<int, int> px){
    if(ap[px.second].size()){
        unite(ap[px.second].back(), px.first);
        ap[px.second].push_back(px.first);
        rb.push({1, 0, px.second});
    }else{
        ap[px.second].push_back(px.first);
        int b = get(px.first);
        val[b]++;
        cur += sz[b];
        rb.push({1, b, px.second});
    }
}



vector<pair<int, int>> ps[4*N];
int q;
void add(int i, int j, pair<int, int> px, int l = 1, int r = q, int p = 1){
    if(l > j || r < i) return;
    if(l >= i && r <= j){
        ps[p].push_back(px);
        return;
    }
    int m = (l + r)/2;
    add(i, j, px, l, m, 2*p);
    add(i, j, px, m+1, r, 2*p+1);
}

void dfs_solve(int l = 1, int r = q, int p = 1){
    int cs = rb.size(); 
    for(auto px : ps[p]){
        add_point(px);
    }
    if(l == r){
        ans[l] = cur;
        while(rb.size() != cs) rollback();
        return;
    }
    int m = (l + r)/2; 
    dfs_solve(l, m, 2*p);
    dfs_solve(m+1, r, 2*p+1);
    while(rb.size() != cs) rollback();
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    cin >> q;
    map<pair<int, int>, int> mp;
    for(int i=1;i<=q;i++){
        int x, y;
        cin >> x >> y;
        if(mp.count({x, y})){
            add(mp[{x, y}], i-1, {x, y});
            mp.erase({x, y});
        }else mp[{x, y}] = i;
    }
    for(auto [k, v] : mp){
        add(v, q, k);
    }
    dfs_solve();
    for(int i=1;i<=q;i++) cout << ans[i] << " ";
    cout << "\n";
}
