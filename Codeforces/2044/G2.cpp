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
        vector<int> adj(n+1);
        vector<int> vis(n+1, 0), d(n+1, 0), in(n+1, 0);
        for(int i=1;i<=n;i++){
            cin >> adj[i];
            in[adj[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int cur = i;
                vis[cur] = 1;
                while(!vis[adj[cur]]){
                    cur = adj[cur];
                    vis[cur] = 1;
                }
                if(vis[adj[cur]] == 1){
                    //cycle
                    do{
                        vis[cur] = 2;
                        cur = adj[cur];
                    }while(vis[cur] != 2);
                }
                vector<int> cv;
                cur = i;
                while(vis[cur] == 1){
                    cv.push_back(cur);
                    cur = adj[cur];
                }
                reverse(cv.begin(), cv.end());
                for(auto x : cv){
                    vis[x] = 2;
                    d[x] = d[adj[x]] + 1;
                }
                
            }
        }
        //if d = 0 then cycle, otherwise d != 0
        //simulate pushing into cycles
        vector<int> xx;
        vector<int> ttc(n+1, 0);
        for(int i=1;i<=n;i++){
            if(in[i] == 0){
                xx.push_back(i);
            }
            if(d[i] != 0){
                ttc[i] = 1;
            }
        }
        while(xx.size()){
            int u = xx.back();
            xx.pop_back();
            int v = adj[u];
            if(d[v] != 0) ttc[v] += ttc[u];
            in[v]--;
            if(in[v] == 0 && d[v] != 0) xx.push_back(v);
        }
        int ans = *max_element(ttc.begin(), ttc.end()) + 2;
        cout << ans << "\n";
    }
}
