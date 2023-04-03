#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int vis[N];
int v[N], cycle[N];
vector<int> c[N];
int cnt = 0;
void dfs(int u){
    vis[u] = 1;
    if(!vis[v[u]]){
        dfs(v[u]);
    }else{
        if(vis[v[u]] == 1){
            ++cnt;
            int nxt = v[u];
            do{
                c[cnt].push_back(nxt);
                cycle[nxt] = cnt;
                nxt = v[nxt];
            }while(nxt != v[u]);
        }
    }
    vis[u] = 2;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    ll ans = 0;
    for(int i=1;i<=cnt;i++) ans += c[i].size();
    cout << ans;
}
