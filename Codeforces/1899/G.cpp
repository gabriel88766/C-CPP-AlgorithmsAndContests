#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;   
int p[N], sz[N];
set<int> st[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1; st[i].clear();}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    for(auto x : st[b]) st[a].insert(x);
    p[b] = a;
    sz[a] += sz[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        init(n);
        vector<vector<int>> adj(n+1);
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> p(n+1), invp(n+1);
        for(int i=1;i<=n;i++){
            int aux;
            cin >> aux;
            st[aux].insert(i);
        }
        vector<pair<int,int>> qrs;
        vector<vector<int>> wq(n+1);
        vector<bool> ans(q);
        function<void(int,int)> dfs = [&](int u, int p){
            for(auto v : adj[u]){
                if(v != p){
                    dfs(v, u);
                    unite(v, u);
                }
            }
            int no = get(u);
            for(auto x : wq[u]){
                auto it = st[no].lower_bound(qrs[x].first);
                if(it != st[no].end() && *it <= qrs[x].second) ans[x] = true;
                else ans[x] = false;
            }
        };
        
        for(int i=0;i<q;i++){
            int l, r, x;
            cin >> l >> r >> x;
            qrs.push_back({l, r});
            wq[x].push_back(i);
        }
        dfs(1, 0);
        for(auto x : ans){
            if(x) cout << "YES\n";
            else cout << "NO\n";
        }
        cout << "\n";
    }
}
