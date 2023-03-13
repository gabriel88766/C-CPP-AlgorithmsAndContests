#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
int vis[N], adj[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> adj[i];

    int cur = 1, cnt = 0;
    while(!vis[cur]){
        vis[cur] = true;
        cur = adj[cur];
        cnt++;
        if(cur == 2) break;
    }
    if(cur == 2) cout << cnt;
    else cout << "-1";
}
