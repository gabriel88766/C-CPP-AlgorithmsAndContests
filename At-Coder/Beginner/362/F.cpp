#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int sub[N];
int n;
void dfs1(int u, int p){
    sub[u] = 1;
    for(auto &v : adj[u]){
        if(v != p){
            dfs1(v, u);
            sub[u] += sub[v];
        }
    }
}
int find_centroid(int u, int p){
    for(auto &v : adj[u]){
        if(v != p){
            if(sub[v] > n/2) return find_centroid(v, u);
        }
    }
    return u;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(n == 2){
        cout << 1 << " " << 2 << "\n";
        return 0;
    }
    dfs1(1, 0);
    int ct = find_centroid(1, 0);
    vector<vector<int>> vv;
    vector<int> cur;
    function<void(int, int)> dfs3 = [&](int c, int p){
        cur.push_back(c);
        for(auto &x : adj[c]){
            if(x != p){
                dfs3(x, c);
            }
        }
    };
    priority_queue<pair<int, int>> pq;
    for(auto &x : adj[ct]){
        cur.clear();
        dfs3(x, ct);
        vv.push_back(cur);
    }
    if(n % 2 == 0){
        for(auto &x : vv){
            if(x.size() + 1 <= n/2){
                x.push_back(ct);
                break;
            }
        }
    }
    for(int i=0;i<vv.size();i++){
        pq.push({vv[i].size(), i});
    }
    while(pq.size()){
        if(pq.size() == 1 ) break;
        auto [a, b] = pq.top();
        pq.pop();
        auto [c, d] = pq.top();
        pq.pop();
        cout << vv[b].back() << " " << vv[d].back() << "\n";
        vv[b].pop_back();
        vv[d].pop_back();
        if(vv[b].size()) pq.push({vv[b].size(), b});
        if(vv[d].size()) pq.push({vv[d].size(), d});
    }
}
