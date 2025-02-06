#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1000;
vector<int> adj[N], adjw[N];

struct Edge{
    ll u, v, w;
};
vector<Edge> edges;
ll dist[N];
int par[N];

vector<int> cycle;
bool negative_cycle_bellman(int n){
    memset(dist, 63, sizeof(dist));
    int cur, x = -1;
    for(int i=0;i<=n;i++){
        x=-1; //if x changed in last iteration, thus x belongs to  a negative cycle.
        for(auto edge : edges){
            if(dist[edge.v] > dist[edge.u] + edge.w){
                dist[edge.v] = dist[edge.u] + edge.w;
                par[edge.v] = edge.u;
                x = edge.v;
            }   
        }
    }
    if(x == -1) return false;
    for(int i=0;i<=n;i++) x = par[x];
    cur = x;
    do{
        cycle.push_back(cur);
        cur = par[cur]; 
    }while(cur != x);
    cycle.push_back(cur);
    reverse(cycle.begin(), cycle.end());
    return true;
}

void bellman(int n){
    memset(dist, 63, sizeof(dist));
    dist[1] = 0;
    for(int i=0;i<n;i++)
        for(auto edge : edges){
            if(dist[edge.u] == INF_LL) continue;
            if(dist[edge.v] > dist[edge.u] + edge.w){
                dist[edge.v] = dist[edge.u] + edge.w;
                par[edge.v] = edge.u;
            }   
        }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    
    map<string, int> mp;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        int x;
        cin >> s >> x;
        mp[s] = x;
    }
    vector<string> st;
    st.push_back("");
    for(char c = 'a'; c<='z'; c++){
        string x;
        x += c;
        st.push_back(x);
    }
    for(char c = 'a'; c<='z'; c++){
        for(char d = 'a'; d<= 'z' ; d++){
            string x;
            x += c;
            x += d;
            st.push_back(x);
        }
    }
    map<string, int> vtx;
    int nn = 0;
    for(auto &x : st){
        vtx[x] = ++nn;
    }
    for(auto &x : st){
        int cn = vtx[x];
        for(char c = 'a'; c <= 'z'; c++){
            string ns = x + c;
            ll w = 0;
            if(mp.count(ns)) w += mp[ns];
            if(ns.size() == 2 && mp.count(ns.substr(1, 1))) w += mp[ns.substr(1, 1)];
            if(ns.size() == 3){
                if(mp.count(ns.substr(1, 2))) w += mp[ns.substr(1, 2)];
                if(mp.count(ns.substr(2, 1))) w += mp[ns.substr(2, 1)];
            }
            if(ns.size() == 3) ns = ns.substr(1, 2);
            int nx = vtx[ns];
            adj[cn].push_back(nx);
            adjw[cn].push_back(w);
            edges.push_back({cn, nx, -w});
        }
    }
    if(negative_cycle_bellman(2*nn)) cout << "Infinity\n";
    else {
        bellman(nn);
        ll ans = INF_LL;
        for(int i=2;i<=nn;i++) ans = min(ans, dist[i]);
        cout << -ans << "\n";
    } 

}
