#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool adj[19][19];
int dp[1 << 18];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a-1][b-1] = adj[b-1][a-1] = true;
    }
    memset(dp, 63, sizeof(dp));
    for (int x=1; x<(1<<n); ++x){
        if(__builtin_popcount(x) == 1){ //init
            dp[x] = 1;
        }else{
            //for each, check if connected.
            vector<int> aux;
            for(int i=0;i<n;i++) if(x & (1 << i)) aux.push_back(i);
            bool ok = true;
            for(int i=0;i<aux.size();i++){
                for(int j=i+1;j<aux.size();j++){
                    if(!adj[aux[i]][aux[j]]) ok = false;
                }   
            }
            if(ok){
                dp[x] = 1;
                continue;
            }
            for (int s=x; s; s=(s-1)&x){ 
                //do something
                dp[x] = min(dp[x], dp[s] + dp[s ^ x]);
            }
        }
    }
    cout << dp[(1 << n) - 1] << "\n";

}
