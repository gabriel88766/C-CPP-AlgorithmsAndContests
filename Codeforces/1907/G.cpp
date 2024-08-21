#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> adj[N];
int dfs_low[N], dfs_num[N], cntT = 0, cntCmp=0;
vector<int> cmp[N], curcmp;
char visc[N];

void tarjan(int u){ //SCC, cmp is in inverse topological order 
    dfs_low[u] = dfs_num[u] = ++cntT;
    visc[u] = 1;
    curcmp.emplace_back(u);
    for(auto v : adj[u]){
        if(!dfs_num[v]) tarjan(v);
        if(visc[v] == 1) dfs_low[u] = min(dfs_low[v], dfs_low[u]);
    }
    if(dfs_low[u] == dfs_num[u]){
        ++cntCmp;
        while(true){
            int v = curcmp.back(); curcmp.pop_back(); visc[v] = 2;
            cmp[cntCmp].emplace_back(v);
            if(v == u) break;
        }
        reverse(cmp[cntCmp].begin(), cmp[cntCmp].end());
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
        int n;
        string s;
        cin >> n >> s;
        vector<int> v(n+1);
        s = " " + s;
        for(int i=1;i<=n;i++){
             cin >> v[i];
             adj[i].push_back(v[i]);
        }
        for(int i=1;i<=n;i++) if(visc[i] == 0) tarjan(i);
        vector<int> ans;
        bool ok = true;
        for(int i=cntCmp;i>=1;i--){
            if(cmp[i].size() == 1){ //not cycle
                int u = cmp[i][0];
                if(s[u] == '1'){
                    ans.push_back(u);
                    s[u] = '0';
                    if(s[adj[u][0]] == '1') s[adj[u][0]] = '0';
                    else s[adj[u][0]] = '1';
                }
            }else{
                //cycle...
                int cnt = 0;
                vector<pair<int,int>> vp;
                for(auto x : cmp[i]){
                    if(s[x] == '1'){
                        cnt++;
                        vp.push_back({1, x});
                    }else vp.push_back({0, x});
                }
                if(cnt % 2){
                    ok = false;
                    break;
                }else{
                    //solve >:D
                    if(cnt == 0) continue;
                    int f1 = -1, s1 = -1;
                    for(int j=0;j<vp.size();j++){
                        if(vp[j].first == 1){
                            if(f1 == -1) f1 = j;
                            else if(s1 == -1) s1 = j;
                            else break;
                        }
                    }
                    int a1 = 0, a2 = 0;
                    int od = -1;
                    for(int j=0;j<vp.size();j++){
                        if(vp[j].first == 1){
                            if(od == -1) od = j;
                            else{
                                a1 += j-od;
                                od = -1;
                            }
                        }
                    }
                    for(int j=f1+1;j<vp.size();j++){
                        if(vp[j].first == 1){
                            if(od == -1) od = j;
                            else{
                                a2 += j - od;
                                od = -1;
                            }
                        }
                    }
                    a2 += f1 + vp.size() - od;
                    if(a1 < a2){
                        od = -1;
                        for(int j=0;j<vp.size();j++){
                            if(vp[j].first == 1){
                                if(od == -1) od = j;
                                else{
                                    od = -1;
                                }
                            }
                            if(od != -1) ans.push_back(vp[j].second);
                        }
                    }else{
                        od = -1;
                        for(int j=f1+1;j<vp.size();j++){
                            if(vp[j].first == 1){
                                if(od == -1) od = j;
                                else{
                                    od = -1;
                                }
                            }
                            if(od != -1) ans.push_back(vp[j].second);
                        }
                        for(int j=0;j<f1;j++) ans.push_back(vp[j].second);
                    }
                }
            }
        }

        if(ok){
            cout << ans.size() << "\n";
            for(auto x : ans) cout << x << " ";
            cout << "\n";
        }else cout << "-1\n";
        cntT = cntCmp = 0;
        curcmp.clear();
        for(int i=1;i<=n;i++){
            adj[i].clear();
            visc[i] = dfs_low[i] = dfs_num[i] = 0;
            cmp[i].clear();

        }
    }
}
