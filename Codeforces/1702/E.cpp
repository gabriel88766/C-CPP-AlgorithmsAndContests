#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];

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
        bool ok = true;
        for(int i=0;i<n;i++){
            int a, b; 
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(a == b){
                ok = false;
            }
        }
        for(int i=1;i<=n;i++) if(adj[i].size() != 2) ok = false;
        if(ok){
            vector<bool> vis(n+1, false);
            for(int i=1;i<=n;i++){
                if(adj[i][0] == adj[i][1]){
                    adj[i].pop_back();
                    adj[i].pop_back();
                    vis[i] = true;
                }
            }
            for(int i=1;i<=n;i++){
                if(!vis[i]){
                    int cur = i;
                    int cnt = 0;
                    int p = -1;
                    do{ 
                        vis[cur] = true;
                        int pnext = cur;
                        if(adj[cur][0] == p) cur = adj[cur][1];
                        else cur = adj[cur][0];
                        p = pnext;
                        cnt++;
                    }while(cur != i);
                    if(cnt % 2) ok = false;
                }
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
        for(int i=1;i<=n;i++) adj[i].clear();

    }
}
