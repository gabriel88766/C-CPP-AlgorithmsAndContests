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
    cout << fixed << setprecision(12);
    int t;
    cin >> t;
    //init
    vector<vector<double>> aux(5005, vector<double>(5005, 0));
    for(int i=2;i<=5000;i+=2){
        aux[i][0] = 1;
        if(i != 2){
            long double div = i-2;
            for(int j=1;j<i;j++){
                // (j-1) times a[i-2][j-2]
                // n-j times a[i-2][j-1]
                if(j != 1) aux[i][j] += aux[i-2][j-2] * (j-1);
                aux[i][j] += aux[i-2][j-1] * (i-j-1);
                aux[i][j] /= div;
            }
        }
    }
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<double> dp(n+1, 0);
        dp[n] = 1;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
 
        
        for(int i=n-1;i>=1;i--){
            if(adj[i].size() == 0) dp[i] = 0;
            else{
                int sz = adj[i].size();
                if(sz % 2){
                    for(int j=0;j<adj[i].size();j++){
                        dp[i] += dp[adj[i][j]];
                    }
                    dp[i] /= sz;
                }else{
                    vector<double> pos;
                    for(int j=0;j<adj[i].size();j++){
                        pos.push_back(dp[adj[i][j]]);
                    }
                    sort(pos.begin(), pos.end(), greater<double>());
                    for(int j=0;j<pos.size();j++){
                        dp[i] += pos[j]*aux[sz][j];
                    }
                    dp[i] /= sz;
                }
                
            }
        }
        cout << dp[1] << "\n";
    }
}