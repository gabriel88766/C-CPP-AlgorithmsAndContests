#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int c[N];
ll d[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    memset(d, 63, sizeof(d));
    vector<vector<int>> st(m+1);
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=m;i++) cin >> c[i];
    for(int i=1;i<=m;i++){
        int sz;
        cin >> sz;
        for(int j=0;j<sz;j++){
            int x;
            cin >> x;
            st[i].push_back(x);
            adj[x].push_back(i);
        }
    }
    d[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [dst, u] = pq.top();
        pq.pop();
        if(dst > d[u]) continue;
        for(auto x : adj[u]){
            if(st[x].size()){
                for(auto &v : st[x]){
                    if(d[v] > d[u] + c[x]){
                        d[v] = d[u] + c[x];
                        pq.push({d[v], v});
                    }
                }
                st[x].clear();
            }
        }
    }
    for(int i=1;i<=n;i++) cout << d[i] << " ";
    cout << "\n";
}
 