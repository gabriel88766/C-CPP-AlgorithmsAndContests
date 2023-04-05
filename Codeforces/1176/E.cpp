#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int d[N];
vector<int> adj[N];
int n;

void bfs(){
    for(int i=1;i<=n;i++) d[i] = INF_INT;
    queue<int> q;
    q.push(1); d[1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[u] + 1 < d[v]){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> n >> m;
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs();
        vector<int> ans[2];
        for(int i=1;i<=n;i++){
            if(d[i] % 2) ans[1].push_back(i);
            else ans[0].push_back(i);
        }
        if(ans[0].size() < ans[1].size()){
            cout << ans[0].size() << "\n";
            for(auto x : ans[0]) cout << x << " ";
            cout << "\n";
        }else{
            cout << ans[1].size() << "\n";
            for(auto x : ans[1]) cout << x << " ";
            cout << "\n";
        }
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
