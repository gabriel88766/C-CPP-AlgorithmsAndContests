#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Edge{
    int u, v, w;
    bool operator< (const Edge &v) const {
        return w < v.w;
    }
};

const int N = 2e5+3;
vector<int> adj[N], adjw[N];

bool check(int n){
    vector<int> c(n+1, -1);
    for(int i=1;i<=n;i++){
        if(c[i] == -1){
            queue<int> q;
            q.push(i);
            c[i] = 0;
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    if(c[v] == -1){
                        c[v] = c[u] ^ 1;
                        q.push(v);
                    }else if(c[v] == c[u]) return false;
                }
            }
        }
    }
    return true;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<Edge> v(m);
    for(int i=0;i<m;i++){
        cin >> v[i].u >> v[i].v >> v[i].w;
    }
    sort(v.begin(), v.end());
    int lo = 1, hi = v.size();
    while(lo != hi){ //max bipartite
        int mid = lo + (hi - lo + 1)/2;
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=0;i<mid;i++){
            adj[v[i].u].push_back(v[i].v);
            adj[v[i].v].push_back(v[i].u);
        } 
        if(check(n)) lo = mid;
        else hi = mid - 1;
    }
    int ans = 2e9+1;
    if(lo != v.size()){
        ans = v[lo].w;
    }
    for(int i=0;i<lo;i++){
        adjw[v[i].u].push_back(v[i].w);
        adjw[v[i].v].push_back(v[i].w);
    }
    for(int i=1;i<=n;i++){
        vector<int> wgs;
        for(auto x : adjw[i]) wgs.push_back(x);
        sort(wgs.begin(), wgs.end());
        if(wgs.size() >= 2) ans = min(ans, wgs[0]+wgs[1]);
    }
    cout << ans << "\n";
}
