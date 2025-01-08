#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
vector<int> adj[N];
int ans[N];
vector<int> dfo;
void dfs(int u){
    for(auto v : adj[u]){
        dfs(v);
    }
    dfo.push_back(u);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=2;i<=n;i++){
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
        dfs(1);
        for(auto &u : dfo){
            if(adj[u].size() == 0) ans[u] = 0;
            else{
                priority_queue<int, vector<int>, greater<int>> pq;
                for(auto v : adj[u]) pq.push(ans[v]);
                while(pq.size() > 2){
                    auto x1 = pq.top();
                    pq.pop();
                    auto x2 = pq.top();
                    pq.pop();
                    pq.push(x2 + 1);
                }
                if(pq.size() == 2) pq.pop();
                ans[u] = pq.top() + 1;
            }
        }
        cout << ans[1] << "\n";
        dfo.clear();
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
