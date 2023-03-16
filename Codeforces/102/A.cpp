#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int adj[101][101];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }
    int cost = INF_INT;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(adj[i][j] && adj[i][k] && adj[j][k]){
                    cost = min(cost, a[i] + a[j] + a[k]);
                }
            }
        }
    }
    if(cost == INF_INT) cout << -1;
    else cout << cost;
}
