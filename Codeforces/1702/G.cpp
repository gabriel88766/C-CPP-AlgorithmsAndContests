#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3, M = 20;
vector<int> adj[N];
int n;
int h[N], anc[N][M];

void dfs(int u, int p = 0){
    h[u] = h[p]+1;
    anc[u][0] = p;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
        }
    }
}

int lca(int a, int b){ 
    if(h[a] > h[b]) swap(a, b);
    int diff = h[b] - h[a];
    for(int i = M-1; i>=0;i--) if(diff & (1 << i)) b = anc[b][i];
    if(a == b) return a;
    for(int i= M-1;i >= 0;i--){
        while(anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
    }
    return anc[a][0];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    h[0] = -1;
    dfs(1);
    for(int j=1;j<M;j++) for(int i=1;i<=n;i++) anc[i][j] = anc[anc[i][j-1]][j-1];
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int k;
        cin >> k;
        set<pair<int,int>> st;
        for(int j=0;j<k;j++){
            int x;
            cin >> x;
            st.insert({-h[x], x});
        }
        vector<int> v1, v2;
        bool ok = true;

        for(auto x : st){
            if(v1.size() == 0) v1.push_back(x.second);
            else{
                int v = x.second;
                int u = v1.back();
                if(lca(u,v) == v) v1.push_back(v);
                else{
                    if(v2.size() == 0) v2.push_back(v);
                    else{
                        u = v2.back();
                        if(lca(u, v) == v) v2.push_back(v);
                        else{
                            ok = false;
                            break;
                        }
                    }
                }
            }
        }
        if(ok && v2.size() != 0){
            int x = lca(v1.back(), v2.back());
            if(x == v1.back() || x == v2.back()){
                if(x == v2.back()) swap(v1,v2);
                if(v1.size() >= 2){
                    int x2 = v1[v1.size()-2];
                    if(v1.back() != lca(v2.back(), x2)) ok = false;
                }
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
