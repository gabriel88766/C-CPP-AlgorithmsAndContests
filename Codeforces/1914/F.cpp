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
        vector<vector<int>> adj(n+1);
        for(int i=2;i<=n;i++){
            int p;
            cin >> p;
            adj[i].push_back(p);
            adj[p].push_back(i);
        }
        vector<int> sub(n+1, 0);
        function<void(int,int)> dfs = [&](int u, int p) -> void {
            sub[u] = 1;
            for(auto v : adj[u]){
                if(v != p){
                    dfs(v, u);
                    sub[u] += sub[v];
                }
            }
        };
        dfs(1, 0);
        function<int(int, int, int)> solve = [&](int u, int p, int qt){
            int sum = 0, maxv = 0;
            int no = 0;
            for(auto v : adj[u]){
                if(v != p){
                    sum += sub[v];
                    if(sub[v] > maxv){
                        maxv = sub[v];
                        no = v;
                    }
                }
            }
            qt = min(qt, sum);
            if(no == 0) return 0;
            if(sum == maxv) return solve(no, u, qt);
            else{
                int p1 = sum - maxv;
                int p2 = qt/2;
                int val = min(p1, p2);
                return val + solve(no, u, qt - 2*val);
            }
        };
        cout << solve(1, 0, n-1) << "\n";
    }
}
