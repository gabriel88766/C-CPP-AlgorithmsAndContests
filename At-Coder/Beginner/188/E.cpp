#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int mn[N], a[N];
vector<int> adj[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        mn[i] = INF_INT;
    }
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int ans = -INF_INT;
    for(int i=1;i<=n;i++){
        for(auto v : adj[i]){
            mn[v] = min({mn[v], a[i], mn[i]});
        }
        if(mn[i] != INF_INT) ans = max(ans, a[i] - mn[i]);
    }
    cout << ans << "\n";
}
