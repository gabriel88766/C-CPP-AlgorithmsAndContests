#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;   
vector<int> adj[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> ans(m);
    map<pair<int,int>, int> mp;
    vector<int> outdg(n+1, 0);
    vector<int> ori(m, 0);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        ans[i] = {a, b};
        mp[{a, b}] = i;
        outdg[a] ^= 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n+1, false);
    bool ok = true;

    function<void(int, int)> dfsT = [&ori, &outdg, &mp, &dfsT, &vis](int u, int p){
        vis[u] = true;
        for(auto v : adj[u]){
            if(!vis[v]){
                dfsT(v, u);
            }
        }
        if(outdg[u] == 1 && p != 0){
            outdg[p] ^= 1;
            if(mp.count({u, p})) ori[mp[{u, p}]] ^= 1;
            else ori[mp[{p, u}]] ^= 1;
        }   
    };

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfsT(i, 0);
            if(outdg[i] == 1){
                ok = false;
            }
        }
        if(!ok) break;
    }
    if(ok){
        for(int i=0;i<m;i++){
            if(ori[i] == 0) cout << ans[i].first << " " << ans[i].second << "\n";
            else cout << ans[i].second << " " << ans[i].first << "\n";
        }
    }else cout << "IMPOSSIBLE\n";
}
