#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int c[N];
int adj[N], vis[N];
int ans = 0;

void dfs(int u){
    int v = adj[u];
    vis[u] = 1;
    if(vis[v] == 1){//cycle
        int cur = u;
        int curv = c[u];
        do{
            curv = min(curv, c[cur]);
            cur = adj[cur];
        }while(cur != u);
        ans += curv;
    }else if(vis[v] == 2){ //cycle already visited
        //do nothing
    }else{//standard
        dfs(v);
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
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int i=1;i<=n;i++){
        cin >> adj[i];
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    cout << ans <<"\n";
}
