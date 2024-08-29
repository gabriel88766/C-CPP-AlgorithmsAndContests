#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> dp[N], adj[N];
int sz = 0;
int v[N], ans[N], loc[N];
multiset<int> ms;
int n;
void dfs(int u){
    int p = 0;
    for(int i=n/2;i>=1;i>>=1){
        while(p + i <= n && dp[p+i].back() < v[u]) p += i;
    }
    dp[p+1].push_back(v[u]);
    ms.insert(p+1);
    ans[u] = *prev(ms.end());
    for(auto v : adj[u]){
        dfs(v);
    }
    ms.erase(ms.find(p+1));
    dp[p+1].pop_back();
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=2;i<=n;i++){
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++) dp[i].push_back(INF_INT);
    dp[0].push_back(0);
    dfs(1);
    for(int i=2;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}   
