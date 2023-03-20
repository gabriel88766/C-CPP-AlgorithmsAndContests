#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5;
vector<int> adj[N];
char vis[N];
int n, ans[N];

void dfs(int u){
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs(i);
            ans[i] = u;
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int r1, r2;
    cin >> n >> r1 >> r2;
    set<pair<int,int>> s;
    for(int i=1;i<=n;i++){
        if(i == r1) continue;
        int aux;
        cin >> aux;
        s.insert({aux, i});
    }
    queue<int> q;
    q.push(r1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        auto it = s.lower_bound({u, 0});
        while(it != s.end() && it->first == u){
            adj[u].push_back(it->second);
            adj[it->second].push_back(u);
            q.push(it->second);
            ++it;
        }
    }
    dfs(r2);
    for(int i=1;i<=n;i++){
        if(r2 == i) continue;
        cout << ans[i] << " ";
    }
}
