#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int ans = 0;
    for(int i=1;i<=n;i++){
        int m;
        cin >> m;
        vector<vector<int>> adj(m+1);
        for(int i=1;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> d(m+1);
        auto bfs = [&](int u){
            fill(d.begin(), d.end(), INF_INT);
            d[u] = d[0] = 0;
            queue<int> q;
            q.push(u);
            while(q.size()){
                auto u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    if(d[v] > d[u] + 1){
                        d[v] = d[u] + 1;
                        q.push(v);
                    }
                }
            }
        };
        bfs(1);
        int ft = max_element(d.begin(), d.end()) - d.begin();
        bfs(ft);
        ans += *max_element(d.begin(), d.end());
    }   
    cout << ans << "\n";
}
