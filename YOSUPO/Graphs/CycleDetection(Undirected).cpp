#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3;
int color[N];
vector<int> adj[N];
int par[N];
int node_begin_cycle;

bool dfs_cycle(int u, int p){
    color[u] = 1;
    par[u] = p;
    for(auto i : adj[u]){
        if(i == p) continue; //uncomment if undirected.
        if(color[i] == 0 && dfs_cycle(i, u)) return true;
        else if(color[i] == 1){
            node_begin_cycle = i;
            par[i] = u;
            return true; 
        }
    }
    color[u] = 2;
    return false;
}
vector<int> find_cycle(int n){ //if returned vector is empty, then no cycle
    vector<int> ans;
    node_begin_cycle = -1;
    for(int i=1;i<=n;i++) color[i] = 0;
    for(int i=1;i<=n;i++) if(!color[i] && dfs_cycle(i, -1)) break;
    if(node_begin_cycle == -1) return ans;
    int s = node_begin_cycle, cur = node_begin_cycle;
    do{
        ans.push_back(cur);
        cur = par[cur];
    }while(cur != s);
    ans.push_back(cur);
    reverse(ans.begin(), ans.end()); //
    return ans;
}
map<pair<int,int>, int> mp;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    bool ok2 = false, ok1 = false;
    int ans1;
    vector<int> ans2v, ans2e;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        if(!mp.count({a+1, b+1})){
            adj[a+1].push_back(b+1);
            adj[b+1].push_back(a+1);
            mp[{a+1, b+1}] = i;
            mp[{b+1, a+1}] = i;
        }else{
            ans2v = {a, b};
            ans2e = {mp[{a+1, b+1}], i};
            ok2 = true;
        }
        if(a == b){
            ok1 = true;
            ans1 = a;
        }
    }
    if(ok1){
        cout << 1 << "\n";
        cout << ans1 << "\n";
        cout << mp[{ans1+1, ans1+1}] << "\n";
        return 0;
    }else if(ok2){
        cout << "2\n";
        for(auto v : ans2v) cout << v << " ";
        cout << "\n";
        for(auto e : ans2e) cout << e << " ";
        cout << "\n";
        return 0;
    }
    auto ans = find_cycle(n);
    if(ans.size()){
        cout << ans.size()-1 << "\n";
        for(int i=0;i<ans.size()-1;i++) cout << ans[i]-1 << " ";
        cout << "\n";
        for(int i=1;i<ans.size();i++){
            cout << mp[{ans[i-1], ans[i]}] << " ";
        }
        cout << "\n";
    }else cout << "-1\n";
}
