#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int vis[N], indg[N];
bool dfs_cycle(int u){
    vis[u] = 1;
    bool ok = false;
    for(auto v : adj[u]){
        if(vis[v] == 0){
            ok |= dfs_cycle(v);
        }else if(vis[v] == 1){
            ok = true;
        }
    }
    vis[u] = 2;
    return ok;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    set<pair<int,int>> st;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        st.insert({a, b});//eliminating multi edges
    }
    for(auto [a, b] : st){
        adj[a].push_back(b);
        indg[b]++;
    }
    bool ok = true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs_cycle(i)) ok = false;
        }
    }
    if(ok){
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=1;i<=n;i++){
            if(indg[i] == 0) pq.push(i);
        }
        vector<int> ans;
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            ans.push_back(u);
            for(auto v : adj[u]){
                indg[v]--;
                if(indg[v] == 0){
                    pq.push(v);
                }
            }
        }
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }else cout << "-1\n";
}
