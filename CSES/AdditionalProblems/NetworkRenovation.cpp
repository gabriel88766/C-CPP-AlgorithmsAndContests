#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
int n;
vector<int> adj[N];
int ql[N];
void dfs(int u, int p){
    if(adj[u].size() == 1 && adj[u][0] == p){
        //leaf
        ql[u]++;
    }
    for(auto &v : adj[u]){
        if(v != p){
            dfs(v, u);
            ql[u] += ql[v];
        }
    }
}
set<int> path;
vector<int> cur;
vector<int> av[N];
void dfs2(int u, int p){
    if(adj[u].size() == 1 && adj[u][0] == p) cur.push_back(u);
    for(auto &v : adj[u]){
        if(path.count(v)) continue;
        if(v != p) dfs2(v, u);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //FREESTYLE!!
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int rt = -1;
    for(int i=1;i<=n;i++){
        if(adj[i].size() == 1){
            rt = i;
            break;
        }
    }
    if(rt == -1) cout << "0\n";//this must not happen
    else{
        dfs(rt, 0);
        int an = rt; 
        int p = 0;
        
        path.insert(an);
        do{
            int j = 0;
            for(auto &v : adj[an]){
                if(v != p && ql[v] > ql[j]) j = v;
            }
            p = an;
            an = j;
            path.insert(an);
        }while(adj[an].size() != 1);
        vector<pair<int, int>> ans;
        ans.push_back({rt, an});
        //TODO : SOLVE!
        priority_queue<pair<int, int>> pq;
        for(auto &x : path){
            for(auto &v : adj[x]){
                if(path.count(v)) continue;
                dfs2(v, x);
                if(cur.size() != 0){
                    av[v] = cur;
                    pq.push({cur.size(), v});
                    cur.clear();
                }
            }
        }
        while(pq.size()){
            if(pq.size() == 1){
                assert(pq.top().first == 1);
                ans.push_back({an, av[pq.top().second].back()});
                pq.pop();
            }else{
                auto x1 = pq.top();
                pq.pop();
                auto x2 = pq.top();
                pq.pop();
                x1.first--;
                x2.first--;
                if(x1.first != 0) pq.push(x1);
                if(x2.first != 0) pq.push(x2);
                ans.push_back({av[x1.second].back(), av[x2.second].back()});
                av[x1.second].pop_back();
                av[x2.second].pop_back();
            }
        }
        
        cout << ans.size() << "\n";
        for(auto &[a, b] : ans) cout << a << " " << b << "\n";
    }
    
}
 