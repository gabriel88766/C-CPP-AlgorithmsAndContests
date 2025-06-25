#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool cant[10][10];
bool ok[1 << 10];
ll dp[1 << 10][11];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, t, m;
    cin >> n >> t >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        cant[a][b] = true;
    }
    for(int i=1;i<(1 << n);i++){
        vector<int> bs;
        for(int j=0;j<n;j++){
            if(i & (1 << j)) bs.push_back(j);
        }
        ok[i] = true;
        for(auto &x : bs){
            for(auto &y : bs){
                if(y <= x) continue;
                if(cant[x][y]) ok[i] = false;
            }
        }
    }
    dp[0][0] = 1;
    for(int i=0;i<(1 << n) - 1; i++){
        for(int j=0;j<t;j++){
            int m = (1 << n) - 1;
            m ^= i;
            assert(m);
            int fb = 31 - __builtin_clz(m);
            for (int s=m; s; s=(s-1)&m){ 
                if(!ok[s]) continue;
                if(s & (1 << fb)){
                    dp[i | s][j+1] += dp[i][j]; 
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][t] << "\n";
    
}
