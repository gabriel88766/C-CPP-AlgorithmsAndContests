#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int a[N], dp[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    set<pair<int,int>> s;
    s.insert({a[1], 1});
    dp[1] = 1;
    while(s.size()){
        auto [val, u] = *s.begin();
        s.erase(s.begin());
        for(auto v: adj[u]){
            if(a[v] < a[u]) continue;
            int nv;
            if(a[v] != a[u]) nv = dp[u] + 1;
            else nv = dp[u];
            if(nv > dp[v]){
                dp[v] = nv;
                s.insert({a[v], v});
            }
        }
    }
    cout << dp[n] << "\n";
}
