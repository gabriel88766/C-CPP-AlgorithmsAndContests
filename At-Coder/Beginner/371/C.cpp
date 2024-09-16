#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int adj1[9][9], adj2[9][9], cs[9][9];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n;
    vector<int> perm;
    for(int i=1;i<=n;i++) perm.push_back(i);
    ll ans = INF_LL;
    cin >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj1[a][b] = 1;
    }
    cin >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj2[a][b] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cin >> cs[i][j];
        }
    }
    do{
        ll cur = 0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int u = perm[i-1], v = perm[j-1];
                if(u > v) swap(u, v);
                if(adj1[i][j]){
                    if(!adj2[u][v]) cur += cs[u][v];
                }else if(adj2[u][v]) cur += cs[u][v];
            }
        }
        ans = min(ans, cur);
    }while(next_permutation(perm.begin(), perm.end()));
    cout << ans << "\n";
}
