#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool check(vector<vector<int>> &adj, vector<vector<string>> &s){
    int n = adj.size();
   
    //check number of nodes
    int qtn = 0;
    for(int i=0;i<n;i++) qtn += adj[i].size();
    qtn /= 2;
    if(qtn != (n-1)){
         return false;
    }
    //check connectivity
    vector<bool> vis(n, false);
    queue<int> q1;
    q1.push(0);
    vis[0] = true;
    while(!q1.empty()){
        auto u = q1.front();
        q1.pop();
        for(auto v : adj[u]){
            if(!vis[v]){
                vis[v] = true;
                q1.push(v);
            }
        }
    }
    for(int i=0;i<n;i++) if(!vis[i]){
         return false;
    }
    //check distances
    vector<vector<int>> d(n, vector<int>(n, INF_INT));
    for(int i=0;i<n;i++){
        d[i][i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(auto v : adj[u]){
                if(d[i][v] == INF_INT){
                    d[i][v] = d[i][u] + 1;
                    q.push(v);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<n;k++){
                if(d[i][k] == d[j][k] && s[i][j][k] == '0') return false; 
                else if(d[i][k] != d[j][k] && s[i][j][k] == '1') return false;
            }
        }
    }
    return true;
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
        cin >> n;
        vector<vector<int>> adj(n);
        vector<vector<string>> s(n, vector<string>(n));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cin >> s[i][j];
            }
        }
        bool ok = false;
        for(int i=1;i<n;i++){
            //suppose 0 -> i node exist
            for(int j=0;j<n;j++) adj[j].clear();
            adj[0].push_back(i);
            adj[i].push_back(0);
            queue<int> q;
            q.push(0);
            q.push(i);
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                int v = adj[u][0];
                for(int j=0;j<n;j++){
                    if(j == v || j == u) continue;
                    int a = j, b = v;
                    if(a > b) swap(a, b);
                    if(s[a][b][u] == '1'){
                        if(adj[j].size() == 0) q.push(j);
                        adj[u].push_back(j);
                        adj[j].push_back(u);
                    }
                }
            }
            if(check(adj, s)){
                ok = true;
                break;
            }
        }
        if(ok){
            cout << "Yes\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<adj[i].size();j++){
                    if(adj[i][j] > i){
                        cout << i+1 << " " << adj[i][j]+1 << "\n";
                    }
                }
            }
        }else cout << "No\n";
    }
}
