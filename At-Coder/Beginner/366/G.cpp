#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>(n+1));
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }
    int p = 1;
    for(int i=1;i<=n;i++){
        int ind = -1;
        for(int j=p;j<=n;j++){
            if(adj[j][i]){
                //ind j has coef i = 1
                ind = j;
                break;
            }
        }
        if(ind != -1){
            swap(adj[p], adj[ind]);
            for(int j=p+1;j<=n;j++){
                if(!adj[j][i]) continue;
                for(int u=1;u<=n;u++){
                    adj[j][u] ^= adj[p][u];
                }
            }
            p++;
        }
    }
    --p;
    vector<ll> ans(n+1, 0);
    bool ok = true;
    int x = 0;
    for(int i=p;i>=1;i--){
        vector<int> df;
        ll cx = 0;
        for(int j=1;j<=n;j++){
            if(adj[i][j] && ans[j] == 0) df.push_back(j);
            else if(adj[i][j]) cx ^= ans[j];
        }
        while(df.size() > 1){
            ans[df.back()] = 1LL << x;
            x++;
            cx ^= ans[df.back()];
            df.pop_back();
        }
        if(df.size()){
            if(cx) ans[df.back()] = cx;
            else{
                ok = false;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++) if(ans[i] == 0) ans[i] = 1;
    if(ok){
        cout << "Yes\n";
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }else cout << "No\n";
}
