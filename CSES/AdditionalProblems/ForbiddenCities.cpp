#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+2;
vector<int> adj[N];
int ans[N], artp[N], low[N], in[N];
set<pair<int,int>> stc[N];
int cnt;
/*struct Query{
    int l, r, j;
};
vector<Query> vq[N];*/

void dfs_artp(int u, int p = -1){
    low[u] = in[u] = ++cnt;
    int ch = 0;
    for(auto v: adj[u]){
        if(v == p) continue;
        if(!in[v]){
            dfs_artp(v, u);
            if(low[v] >= in[u] && p != -1){
                artp[u] = true;
            }
            if(low[v] >= in[u]){
                stc[u].insert({cnt, in[v]});
            }
            ch++;
            low[u] = min(low[u], low[v]);
        }else low[u] = min(low[u], in[v]);
    }
    if(p == -1 && ch > 1){
        //artic point. if removed, ch-1 more components
        artp[u] = true;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_artp(1);
    for(int i=0;i<q;i++){
        int l, r, c;
        cin >> l >> r >> c;
        if(l == c || r == c) cout << "NO\n";
        else if(!artp[c]) cout << "YES\n";
        else{
            auto it1 = stc[c].upper_bound({in[l], 0});
            auto it2 = stc[c].upper_bound({in[r], 0});
            bool o1, o2;
            if(it1 == stc[c].end() || it1->second > in[l]) o1 = true;
            else o1 = false;
            if(it2 == stc[c].end() || it2->second > in[r]) o2 = true;
            else o2 = false;

            if(o1 || o2){
                if(o1 != o2) cout << "NO\n";
                else cout << "YES\n";
            }else if(it1 == it2) cout << "YES\n";
            else cout << "NO\n";
        }
    }

}
