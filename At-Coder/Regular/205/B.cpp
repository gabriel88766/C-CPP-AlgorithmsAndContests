#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5 + 3;
set<int> adj[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    if(n % 2 == 0){
        for(int i=1;i<=n;i+=2){
            if(adj[i].count(i+1)){
                adj[i].erase(i+1);
                adj[i+1].erase(i);
            }else{
                adj[i].insert(i+1);
                adj[i+1].insert(i);
            }
        }    
    }

    set<pair<int, int>> adjc;
    for(int i=1;i<=n;i++){
        adjc.insert({adj[i].size(), i});
    }
    
    while(prev(adjc.end())->first >= 2){
        auto [a, x] = *prev(adjc.end());
        int v1 = *adj[x].begin();
        int v2 = *next(adj[x].begin());
        adjc.erase({adj[x].size(), x});
        adjc.erase({adj[v1].size(), v1});
        adjc.erase({adj[v2].size(), v2});
        adj[x].erase(v1);
        adj[v1].erase(x);
        adj[x].erase(v2);
        adj[v2].erase(x);
        if(adj[v1].count(v2)){
            adj[v1].erase(v2);
            adj[v2].erase(v1);
        }else{
            adj[v1].insert(v2);
            adj[v2].insert(v1);
        }
        adjc.insert({adj[x].size(), x});
        adjc.insert({adj[v1].size(), v1});
        adjc.insert({adj[v2].size(), v2});
    }
    ll ans = n;
    ans *= (n-1);
    ans /= 2;
    ll cnt = 0;
    for(int i=1;i<=n;i++){
        cnt += adj[i].size();
    }
    cnt /= 2;
    ans -= cnt;
    cout << ans << "\n";
}
