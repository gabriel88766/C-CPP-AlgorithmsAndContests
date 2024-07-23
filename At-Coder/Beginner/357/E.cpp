#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int v[N];
ll vis[N];
ll rc[N];
void dfs(int u){
    vis[u] = 1;
    if(vis[v[u]] == 1){
        //cycle
        int cur = u;
        int cnt = 0;
        do{
            cur = v[cur];
            cnt++;
        }while(cur != u);
        cnt--;
        do{
            rc[cur] = cnt;
            cur = v[cur];
        }while(cur != u);
    }else if(vis[v[u]] == 2){
        //already reached sometime
        rc[u] = rc[v[u]] + 1;
    }else{
        dfs(v[u]);
        if(rc[u] == 0) rc[u] = rc[v[u]] + 1; 
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
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    for(int i=1;i<=n;i++){
        if(vis[i] == 0){
            dfs(i);
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans += rc[i];
    }
    ans += n;
    cout << ans << "\n";


}
