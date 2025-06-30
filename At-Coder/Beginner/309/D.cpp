#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
vector<int> adj[N];
int d[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(d, 63, sizeof(d));
    auto bfs = [&](int u){
        d[u] = 0;
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
    bfs(n1+n2);
    int m1 = 0, m2 = 0;
    for(int i=1;i<=n1;i++) m1 = max(m1, d[i]);
    for(int i=n1+1;i<=n2+n1;i++) m2 = max(m2, d[i]);
    cout << m1 + m2 + 1 << "\n";
}
 