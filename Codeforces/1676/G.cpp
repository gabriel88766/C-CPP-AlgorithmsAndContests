#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 4005;
vector<int> adj[N];
int B[N], W[N];
string s;
int ans;

void dfs(int u){
    if(s[u-1] == 'W') W[u]++;
    else B[u]++;
    for(auto i : adj[u]){
        dfs(i);
        W[u] += W[i];
        B[u] += B[i];
    }
    if(W[u] == B[u]) ans++;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ans = 0;
        for(int i=1;i<=n;i++) {adj[i].clear(); B[i] = W[i] = 0;}
        for(int i=2;i<=n;i++){
            int aux;
            cin >> aux;
            adj[aux].push_back(i);
        }
        cin >> s;
        dfs(1);
        cout << ans << "\n";
    }
}
