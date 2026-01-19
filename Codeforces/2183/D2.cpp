#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int h[N], par[N], cl[N];
void dfs(int u, int p){
    h[u] = h[p] + 1;
    par[u] = p;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
        }
    }
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        h[0] = -1;
        dfs(1, 0);
        int mx = *max_element(h, h + n + 1);
        vector<vector<int>> v(mx+1);
        for(int i=1;i<=n;i++){
            v[h[i]].push_back(i);
        }
        int ans = 1;
        cl[1] = 1;
        for(int i=1;i<=mx;i++){
            set<int> ap;
            for(auto x : v[i]) ap.insert(par[x]);
            int cur;
            if(ap.size() == 1){
                cur = v[i].size() + 1;
                int fb = cl[*ap.begin()];
                int c = 0;
                for(int j=0;j<v[i].size();j++){
                    c++;
                    if(c == fb) c++;
                    cl[v[i][j]] = c;
                }
            }else{
                cur = v[i].size();
                map<int, bool> mp;
                vector<pair<int, int>> ch;
                vector<int> aux;
                vector<int> nch;
                for(int j=0;j<v[i].size();j++){
                    if(mp.count(cl[par[v[i][j]]])){ nch.push_back(v[i][j]); continue;}
                    mp[cl[par[v[i][j]]]] = true;
                    ch.push_back({cl[par[v[i][j]]], v[i][j]});
                    aux.push_back(cl[par[v[i][j]]]);
                }
                int c = 0;
                for(auto x : nch){
                    c++;
                    while(mp.count(c)) c++;
                    cl[x] = c;
                }
                while(true){
                    shuffle(aux.begin(), aux.end(), rng);
                    bool ok = true;
                    for(int j=0;j<ch.size();j++){
                        if(ch[j].first == aux[j]) ok = false;
                    }
                    if(ok) break;
                }
                for(int j=0;j<ch.size();j++){
                    cl[ch[j].second] = aux[j];
                }
            } 
            ans = max(ans, cur);
        }
        cout << ans << "\n";
        vector<vector<int>> ansv(ans+1);
        for(int i=1;i<=n;i++) ansv[cl[i]].push_back(i);
        for(int i=1;i<ansv.size();i++){
            cout << ansv[i].size() << " ";
            for(auto x : ansv[i]) cout << x << " ";
            cout << "\n";
        }
        for(int i=1;i<=n;i++){
            h[i] = par[i] = cl[i] = 0;
            adj[i].clear();
        }
    }
}
