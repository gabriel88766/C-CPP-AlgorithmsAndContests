#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<pair<ll, ll>> adj[N];
ll d[N][4];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    memset(d, 63, sizeof(d));
    d[1][0] = 0;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    pq.push({0, 1, 0});
    while(pq.size()){
        auto [dst, u, x] = pq.top();
        pq.pop();
        if(dst > d[u][x]) continue;
        for(auto [v, w] : adj[u]){
            for(int j=0;j<=3;j++){
                if((x & j) != 0) continue;
                ll nw = dst + w;
                if(j & 1) nw -= w;
                if(j & 2) nw += w;
                ll nj = j | x;
                if(d[v][nj] > nw){
                    d[v][nj] = nw;
                    pq.push({d[v][nj], v, nj});
                }
            }
        }
    }
    for(int i=2;i<=n;i++) cout << d[i][3] << " ";
    cout << "\n";
}
