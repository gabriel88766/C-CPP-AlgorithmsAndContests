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
        int n, k;
        cin >> n >> k;
        vector<int> v(n+1);
        vector<vector<int>> adj(n);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            if(v[i] <= n){
                // v[i] -> n, state ini = v[i] - i. fin state = n - i
                int src = v[i] - i;
                if(src < 0) src += n;
                int dest = n - i;
                adj[dest].push_back(src);
            }
        }
        vector<int> d(n, -1);
        queue<int> q;
        q.push(0);
        int maxv = 0;
        d[0] = 0;
        bool inf = false;
        while(q.size()){
            auto u = q.front();
            q.pop();
            for(auto v : adj[u]){
                if(d[v] == -1){
                    d[v] = d[u] + 1;
                    maxv = max(maxv, d[v]);
                    q.push(v);
                }else inf = true;
            }
        }
        //cout << inf << " " << maxv << "\n";
        if(inf) cout << "Yes\n";
        else if(maxv >= k) cout << "Yes\n";
        else cout << "No\n";
    }
}
