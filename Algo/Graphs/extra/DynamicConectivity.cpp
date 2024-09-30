#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//DSU with rollback
const int N = 1e5+3;   
int p[N], sz[N], ans[N];
stack<pair<int,int>> rb;

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ //log n
    return p[a] == a ? a : get(p[a]);
}

int cmp;

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
    rb.push({b, a});
    cmp--;
}

void rollback(){
    if(rb.size() == 0){
        assert(false); //?? this may be a mistake.
        return;
    }
    auto [b, a] = rb.top();
    rb.pop();
    p[b] = b;
    sz[a] -= sz[b];
    cmp++;
}


int k;
vector<pair<int,int>> st[4*N];
void add(int i, int j, pair<int,int> edg, int l = 0, int r = k, int p = 1){
    if(r < i || l > j) return;
    if(l >= i && r <= j){
        st[p].push_back(edg);
        return;
    }
    int m = (l + r)/2;
    add(i, j, edg, l, m, 2*p);
    add(i, j, edg, m+1, r, 2*p+1);
}

void dfs(int l = 0, int r = k, int p = 1){
    int sz = rb.size();
    for(int i=0;i<st[p].size();i++){
        auto [a, b] =  st[p][i];
        unite(a, b);
    }
    if(l == r){
        ans[l] = cmp;
    }else{
        int m = (l + r)/2;
        dfs(l, m, 2*p);
        dfs(m+1, r, 2*p+1);
    }
    while(rb.size() != sz) rollback();
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m;
    cin >> n >> m >> k;
    cmp = n;
    map<pair<int,int>, vector<int>> mp;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        mp[{a, b}].push_back(0);
    }
    for(int i=1;i<=k;i++){
        int x, a, b;
        cin >> x >> a >> b;
        if(a > b) swap(a, b);
        mp[{a, b}].push_back(i);
    }
    for(auto &[edg, v] : mp){
        if(v.size() % 2) v.push_back(k+1);
        for(int i=0;i<v.size();i+=2){
            add(v[i], v[i+1] - 1, edg);
        }
    }
    dfs();
    for(int i=0;i<=k;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
