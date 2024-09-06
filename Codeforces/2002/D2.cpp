#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+2;
vector<int> adj[N];
int sub[N], par[N];
set<int> adji[N];
bool ok[N];
int cnt = 0;

void dfs(int u){
    sub[u] = 1;
    for(auto v : adj[u]){
        dfs(v);
        sub[u] += sub[v];
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
        int n, q;
        cin >> n >> q;
        for(int i=2;i<=n;i++){
            cin >> par[i];
            adj[par[i]].push_back(i);
        }
        dfs(1);
        vector<int> p(n+1), ip(n+1);
        for(int i=1;i<=n;i++){
            cin >> p[i];
            ip[p[i]] = i;
        }
        for(int i=1;i<=n;i++){
            for(auto v : adj[i]){
                adji[i].insert(ip[v]);
            }
            ok[i] = true;
            if(adji[i].size()){
                if(ip[i] + 1 != *adji[i].begin()) ok[i] = false;
                if(ip[i] + sub[i] - 1 != *prev(adji[i].end()) + sub[p[*prev(adji[i].end())]] - 1) ok[i] = false;
            }
            if(ok[i]){
                cnt++;
            }
        }
        for(int i=0;i<q;i++){
            int a, b;
            cin >> a >> b;
            
            
            if(par[p[a]] != par[p[b]]){
                if(par[p[a]]){
                    assert(adji[par[p[a]]].count(a));
                    adji[par[p[a]]].erase(a);
                    adji[par[p[a]]].insert(b);
                }
                if(par[p[b]]){
                    assert(adji[par[p[b]]].count(b));
                    adji[par[p[b]]].erase(b);
                    adji[par[p[b]]].insert(a);
                }
                
                
            }
            swap(ip[p[a]], ip[p[b]]); //ok
            swap(p[a], p[b]); //ok
            vector<int> chk = {p[a], p[b]};
            if(par[p[a]]) chk.push_back(par[p[a]]);
            if(par[p[b]]) chk.push_back(par[p[b]]);

            for(auto x : chk){
                bool ok2 = true;
                if(adji[x].size()){
                    if(ip[x] + 1 != *adji[x].begin()) ok2 = false;
                    if(ip[x] + sub[x] - 1 != *prev(adji[x].end()) + sub[p[*prev(adji[x].end())]] - 1) ok2 = false;
                }
                if((ok2) && (!ok[x])) cnt++;
                if((!ok2) && (ok[x])) cnt--;
                ok[x] = ok2;
            }
            if(cnt == n) cout << "YES\n";
            else cout << "NO\n";

        }



        for(int i=1;i<=n;i++){
            adj[i].clear();
            ok[i] = 0;
            adji[i].clear();
        }
        cnt = 0;
    }
}
