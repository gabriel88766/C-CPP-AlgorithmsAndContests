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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+1);
        vector<vector<int>> adj(n+1);
        vector<int> h(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int q;
        cin >> q;
        vector<vector<int>> anc(n+1, vector<int>(20));
        vector<vector<int>> fst(n+1, vector<int>(30, 0));
        h[0] = -1;
        function<void(int,int)> dfs = [&dfs, &adj, &anc, &h, &a, &fst](int u, int p){
            h[u] = h[p] + 1;
            anc[u][0] = p;
            for(int i=0;i<30;i++){
                if((1 << i) & a[u]){
                    fst[u][i] = u;
                }
            }
            for(auto v : adj[u]){
                if(v != p){
                    for(int i=0;i<30;i++){
                        fst[v][i] = fst[u][i];
                    }
                    dfs(v, u);
                }
            }
        };
        dfs(1, 0);
        function<int(int,int)> lca = [&h, &anc](int a, int b){
            if(h[a] > h[b]) swap(a, b);
            for(int i=19;i>=0;i--){
                if(h[b] - h[a] >= (1 << i)) b = anc[b][i];
            }
            if(a == b) return a;
            for(int i = 19; i>= 0; i--){
                if(anc[a][i] != anc[b][i]){
                    a = anc[a][i];
                    b = anc[b][i];
                }
            }
            return anc[a][0];
        };
        for(int i=1;i<20;i++){
            for(int j=1;j<=n;j++){
                anc[j][i] = anc[anc[j][i-1]][i-1];
            }
        }
        
        for(int i=1;i<=q;i++){
            int a, b;
            cin >> a >> b;
            int c = lca(a, b);
            vector<pair<int,int>> sum;
            int ans = 0, tt = 0;
            for(int j=0;j<30; j++){
                if(h[fst[a][j]] < h[c] && h[fst[b][j]] < h[c]){
                    //do nothing, impossible bit
                }else{
                    tt++;
                    int first, last;
                    if(h[fst[a][j]] >= h[c]){
                        first = h[a] - h[fst[a][j]];
                    }else{
                        int cur = b;
                        for(int k=19;k>=0;k--){
                            if(h[fst[anc[cur][k]][j]] >= h[c]) cur = fst[anc[cur][k]][j];
                        }
                        first = (h[a]-h[c]) + h[cur] - h[c];
                    }
                    if(h[fst[b][j]] >= h[c]){
                        last = (h[a]-h[c]) + h[fst[b][j]] - h[c];
                    }else{
                        int cur = a;
                        for(int k=19;k>=0;k--){
                            if(h[fst[anc[cur][k]][j]] >= h[c]) cur = fst[anc[cur][k]][j];
                        }
                        last = h[a] - h[cur];
                    }
                    sum.push_back({first, 1});
                    sum.push_back({last+1, -1});
                }
            }
            sort(sum.begin(), sum.end());
            int cur = 0;
            for(auto x : sum){
                cur += x.second;
                ans = max(ans, tt+cur);
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
