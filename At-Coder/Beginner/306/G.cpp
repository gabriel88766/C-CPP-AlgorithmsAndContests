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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        vector<int> dg(n+1, 0); // gcd of all cycles ending in i
        vector<int> ld(n+1, -1);
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        queue<pair<int, int>> qp;
        ld[1] = 0;
        qp.push({1, 0});
        while(!qp.empty()){
            auto [u, dx] = qp.front();
            // cout << u << " " << dx << "\n";
            qp.pop();
            for(auto v : adj[u]){
                if(ld[v] == -1){
                    ld[v] = dx + 1;
                    qp.push({v, dx + 1});
                }else if(dx + 1 != ld[v] && gcd(dx + 1 - ld[v], dg[v]) != dg[v]){
                    dg[v] = gcd(dx + 1 - ld[v], dg[v]);
                    qp.push({v, dx + 1});
                    ld[v] = dx + 1;
                }
            }
        }
        // cout << dg[1] << "\n";
        if(dg[1] != 0){
            while(dg[1] % 2 == 0) dg[1] /= 2;
            while(dg[1] % 5 == 0) dg[1] /= 5;
            if(dg[1] == 1) cout << "Yes\n";
            else cout << "No\n";
        }else cout << "No\n";
    }
}
