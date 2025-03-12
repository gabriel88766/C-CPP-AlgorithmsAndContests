#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5;
vector<int> adj[N];
int d[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int q;
    cin >> q;
    memset(d, 63, sizeof(d));
    for(int i=0;i<q;i++){
        int x, k;
        cin >> x >> k;
        vector<int> av;
        int p = 0;
        av.push_back(x);
        d[x] = 0;
        while(p < av.size()){
            int u = av[p];
            p++;
            if(d[u] == k) continue;
            for(auto &v : adj[u]){
                if(d[v] > d[u] + 1){
                    d[v] = d[u] + 1;
                    av.push_back(v);
                }
            }
        }
        int ans = 0;
        for(auto &x : av){
            ans += x;
            d[x] = INF_INT;
        }
        cout << ans << "\n";
    }
}
