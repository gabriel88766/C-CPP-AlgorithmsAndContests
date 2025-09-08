#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> adj[N], adji[N];
int fb[N];
int ans[N];
void solve(int u, int p){
    int cur = 1;
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        int j = adji[u][i];
        if(v == p) continue;
        if(cur == fb[u]) cur++;
        fb[v] = cur;
        ans[j] = cur;
        solve(v, u);
        cur++;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        adji[a].push_back(i);
        adji[b].push_back(i);
    }
    int ansc = 0;
    for(int i=1;i<=n;i++) ansc = max(ansc, (int)adj[i].size());
    cout << ansc << "\n";
    solve(1, 0);
    for(int i=1;i<n;i++){
        cout << ans[i] << "\n";
    }
}
