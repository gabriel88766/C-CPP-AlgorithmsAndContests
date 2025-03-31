#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll adj[15][15];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    memset(adj, 0xFF, sizeof(adj));
    for(int i=0;i<m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = adj[b][a] = c;
    }
    ll ans = 1LL << 61;
    for(int i=1;i<(1 << n);i++){
        if(__builtin_popcount(i) < 2) continue;
        vector<int> cv;
        for(int j=0;j<n;j++){
            if(i & (1 << j)) cv.push_back(j+1);
        }
        
        do{
            if(cv[0] != 1 || cv.back() != n) continue;
            ll cx = 0;
            bool ok = true;
            for(int i=1;i<cv.size();i++){
                int u = cv[i-1], v = cv[i];
                if(adj[u][v] == -1) ok = false;
                else cx ^= adj[u][v];
            }
            if(ok) ans = min(ans, cx);
        }while(next_permutation(cv.begin(), cv.end()));
    }
    cout << ans << "\n";
}
