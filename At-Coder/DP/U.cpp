#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[1 << 16];
ll val[16][16];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> val[i][j];
        }
    }
    for(int i=0;i < (1 << n); i++){
        //init everybody in same group O(n^2 * 2^n) fast enough
        vector<int> aux;
        for(int j=0;j<n;j++) if(i & (1 << j)) aux.push_back(j);
        for(int j=0;j<aux.size();j++){
            for(int k=j+1;k<aux.size();k++){
                dp[i] += val[aux[j]][aux[k]];
            }
        }
        //all submasks, O(3^n) fast enough too
        for (int s=i; s; s=(s-1)&i){ 
            dp[i] = max(dp[i], dp[s] + dp[i ^ s]);
        }
    }
    cout << dp[(1 << n) - 1] << "\n";
}   
