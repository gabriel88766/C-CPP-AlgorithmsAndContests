#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;

struct Compare{
    bool operator() (pair<int,int> u, pair<int,int> v) const{
        if(u.first != v.first) return u.first > v.first;
        else return u.second < v.second;
    }
};

vector<int> adj[N];
set<pair<int, int>, Compare> ch[N];
ll v[N];
int par[N], sub[N];
ll vst[N];

void dfs(int u, int p = 0){
    vst[u] = v[u];
    sub[u]++;
    par[u] = p;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            ch[u].insert({sub[v], v});
            vst[u] += vst[v];
            sub[u] += sub[v];
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1);
    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            cout << vst[b] << "\n";
        }else{
            //rotate
            if(!ch[b].empty()){
                int c = ch[b].begin()->second;
                ch[b].erase(*ch[b].begin());
                ch[par[b]].erase({sub[b], b});
                vst[b] -= vst[c];
                vst[c] += vst[b];
                sub[b] -= sub[c];
                sub[c] += sub[b];
                ch[par[b]].insert({sub[c], c});
                ch[c].insert({sub[b], b});
                par[c] = par[b];
                par[b] = c;
            }
        }
    }
}
