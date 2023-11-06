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
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i=0;i<m;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    bool ok = true;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        if(a[i] == b[i]) ok = false;
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    vector<int> d(n+1, -1);
    for(int i=1;i<=n;i++){
        if(d[i] == -1){
            queue<int> q;
            q.push(i);
            d[i] = 0;
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    if(d[v] == -1){
                        d[v] = d[u] ^ 1;
                        q.push(v);
                    }else if(d[v] == d[u]) ok = false;
                }
            }
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
 