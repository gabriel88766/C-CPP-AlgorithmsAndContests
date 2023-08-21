#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int indg[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> v(n+1), ans(n+1);
        for(int i=1;i<=n;i++){
             cin >> ans[i];
        }
        for(int i=1;i<=k;i++){
            int aux;
            cin >> aux;
            ans[aux] = 0;
        }
        for(int i=1;i<=n;i++){
            int m;
            cin >> m;
            for(int j=1;j<=m;j++){
                int x;
                cin >> x;
                adj[i].push_back(x);
                indg[x]++;
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++) if(indg[i] == 0) q.push(i);
        vector<int> topo;
        while(!q.empty()){ //priority queue for first lexicographical order,
            int u = q.front(); //if(q.size() >= 2) then not unique.
            q.pop();
            for(auto x : adj[u]){
                indg[x]--;
                if(indg[x] == 0) q.push(x);
            }
            topo.push_back(u);
        }
        reverse(topo.begin(), topo.end());
        for(auto x : topo){
            if(adj[x].size()){
                ll curc = 0;
                for(auto v : adj[x]){
                    curc += ans[v];
                }
                if(curc < ((ll)INF_INT)){
                    ans[x] = min(ans[x], (int)curc);
                }
            }   
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
        for(int i=1;i<=n;i++){
            adj[i].clear();
            indg[i] = 0;
        }
    }
}