#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int adj[N], cst[N];
int vis[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> adj[i];
    for(int i=1;i<=n;i++) cin >> cst[i];
    ll ans = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int cur = i;
            vector<int> av;
            while(vis[cur] == 0){
                av.push_back(cur);
                vis[cur] = 1;
                cur = adj[cur];
            }
            if(vis[cur] == 2){
                //then it's ok
                for(auto &v : av) vis[v] = 2;
            }else{
                //then cycle
                int mn = INF_INT;
                vector<int> v2;
                int bg = cur;
                do{
                    v2.push_back(cur);
                    cur = adj[cur];
                }while(cur != bg);
                for(auto &x : v2){
                    mn = min(mn, cst[x]);
                }
                ans += mn;
                for(auto &x : av) vis[x] = 2;
            }
        }
    }
    cout << ans << "\n";
}
