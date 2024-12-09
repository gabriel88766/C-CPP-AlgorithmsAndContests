#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 4e5+3;
vector<int> adj[N];
int ans[N];
char pr[N];
void init(){
    memset(pr, 1, sizeof(pr));
    pr[1] = 0;
    for(int i=2;i<N;i++){
        if(pr[i]){
            for(int j=2*i;j<N;j+=i) pr[j] = 0;
        }
    }
}


int cur = 0;
void dfs(int u, int p){
    ++cur;
    while(pr[cur - ans[p]]) cur++;
    ans[u] = cur;
    for(auto v : adj[u]) if(v != p) dfs(v, u);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cur = 0;
        dfs(1, 0);
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}
