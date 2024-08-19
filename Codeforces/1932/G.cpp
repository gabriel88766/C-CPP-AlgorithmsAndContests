#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5 + 1;
ll l[N], s[N], H;


vector<ll> adj[N];
ll dist[N];
ll gcd_euclid(ll a, ll b, ll &x, ll &y){ //solves ax+by = g where g = gcd(a,b)
    if(b == 0){ //meaning 1 * a - 0 * 0 = a, (gcd)
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd_euclid(b, a % b, x1, y1); //if b > a then this step reverses it
    x = y1;
    y = x1 - y1 * (a/b); 
    return d;
}
bool find_xy(ll a, ll b, ll c, ll &x, ll &y){ //first solution for x > 0
    ll g = gcd_euclid(abs(a), abs(b), x, y);
    if(c % g) return false;
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    x = (x * c/g)  % (abs(b)/g); //mulmod  if risk of overflow
    if(x < 0) x += abs(b)/g;
    y = (c - a*x) / (b/g);
    return true;
}

void dijkstra(int src, int n){
    for(int i=1;i<=n;i++) dist[i] = INF_LL;
    dist[src] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        auto d = pq.top().first;
        auto u = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;
        for(int i=0;i<adj[u].size();i++){
            ll v = adj[u][i];
            ll w = d;
            //(l[u] + s[u]*((x-1) % H)) % H = (l[v] + s[v]*((x-1) % H)) % H, x > d
            //l[v] - l[u] = x * (s[v] - s[u]) + H * y
            ll g = gcd(H, abs(s[v] - s[u]));
            // cout << g << " " << u << " " << v << " " << abs(l[v] - l[u]) << "\n";
            if((abs(l[v] - l[u]) % g)) continue;
            ll x, y;
            find_xy(s[u] - s[v], H, l[v] - l[u], x, y);
            // x + (H/g) * k >= d
            if(x < d){
                ll k = (d-x-1)/(H/g) + 1;
                x += (H/g) * k;
                x++;
            }else x++;
            // cout << u << " " << v << " " << x << "\n";
            if(dist[v] > x){
                dist[v] = x;
                pq.push({dist[v], v});
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
        ll n, m;
        cin >> n >> m >> H;
        for(int i=1;i<=n;i++) cin >> l[i];
        for(int i=1;i<=n;i++) cin >> s[i];
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dijkstra(1, n);
        if(dist[n] == INF_LL) cout << "-1\n";
        else cout << dist[n] << "\n";
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
