#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
int n;
vector<int> getCentroid(vector<vector<int>> &adj){
    vector<int> sub(n+1, 0);
    function<void(int,int)> dfs = [&](int u, int p){
        sub[u] = 1;
        for(auto v : adj[u]){
            if(v != p){
                dfs(v, u);
                sub[u] += sub[v];
            }
        }
    };
    dfs(1, 0);
    vector<int> ans;
    function<void(int,int)> dfs2 = [&](int u, int p){
        bool ok = true;
        if(n - sub[u] > n/2) ok = false;
        for(auto v : adj[u]){
            if(v != p){
                dfs2(v, u);
                if(sub[v] > n/2) ok = false;
            }
        }
        if(ok) ans.push_back(u);
    };
    dfs2(1, 0);
    return ans;
}
 
void generate(vector<vector<int>> &adj, map<vector<int>, int> &mp, int rt){
    int cnt = mp.size();
    function<int(int,int)> dfs = [&](int u, int p){
        vector<int> ch;
        for(auto v : adj[u]){
            if(v != p){
                ch.push_back(dfs(v, u));
            }
        }
        sort(ch.begin(), ch.end());
        if(!mp.count(ch)) mp[ch] = ++cnt;
        return mp[ch];
    };
    dfs(rt, 0);
}
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>> adj1(n+1), adj2(n+1);
        for(int i=1;i<n;i++){
            int a,b;
            cin >> a >> b;
            adj1[a].push_back(b);
            adj1[b].push_back(a);
        }
        for(int i=1;i<n;i++){
            int a,b;
            cin >> a >> b;
            adj2[a].push_back(b);
            adj2[b].push_back(a);
        }
        auto v1 = getCentroid(adj1);
        auto v2 = getCentroid(adj2);
        if(v1.size() != v2.size()) cout << "NO\n";
        else{
            if(v1.size() == 2){
                map<vector<int>, int> mp1;
                map<vector<int>, int> mp2;
                generate(adj1, mp1, v1[0]);
                auto sz1 = mp1.size();
                generate(adj1, mp2, v1[1]);
                auto sz2 = mp2.size();
                generate(adj2, mp1, v2[0]);
                generate(adj2, mp2, v2[0]);
                if(mp1.size() == sz1 || mp2.size() == sz2) cout << "YES\n";
                else cout << "NO\n";
            }else{
                map<vector<int>, int> mp;
                generate(adj1, mp, v1[0]);
                auto sz = mp.size();
                generate(adj2, mp, v2[0]);
                if(sz == mp.size()) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}