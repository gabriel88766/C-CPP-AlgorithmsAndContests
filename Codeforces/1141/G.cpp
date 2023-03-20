#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<pair<int,int>> adj[N];
int ans[N];
int n, k, r;

void dfs(int u, int p=-1, int lc = -1){
    int cc = 0;
    for(auto v : adj[u]){
        if(cc == lc) cc = (cc + 1) % r;
        if(v.first != p){
            ans[v.second] = cc;
            dfs(v.first, u, cc); 
            cc = (cc + 1) % r;
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> k;
    vector<pair<int,int>> oans;
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].emplace_back(b,i);
        adj[b].emplace_back(a,i);
    }
    vector<int> qt;
    for(int i=1;i<=n;i++) qt.push_back(adj[i].size());
    sort(qt.begin(), qt.end(), greater<int>());
    r = qt[k];
    cout << r << "\n";
    dfs(1);
    for(int i=1;i<n;i++){
        cout << ans[i]+1 << " ";
    }
}
