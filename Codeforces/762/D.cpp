#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
ll dp[9], ndp[9];
ll gr[N][3];
void setd(ll *dp){
    for(int i=0;i<9;i++) dp[i] = -INF_LL;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    setd(dp);
    int n;
    cin >> n;
    for(int j=0;j<3;j++){
        for(int i=1;i<=n;i++){
            cin >> gr[i][j];
        }
    }
    dp[0] = 0;
    vector<int> adj[9] = {
        {0, 1, 2},
        {3, 4, 5},
        {2, 6, 7, 8},
        {3, 4, 5}, 
        {0, 1, 2},
        {6, 7, 8},
        {6, 7, 8},
        {3, 4, 5},
        {0, 1, 2, 8}
    };
    vector<int> nds[9] = {
        {1, 0, 0},
        {1, 1, 0},
        {1, 1, 1},
        {0, 1, 0},
        {1, 1, 0},
        {0, 1, 1},
        {0, 0, 1},
        {0, 1, 1},
        {1, 1, 1}
    };
    for(int i=1;i<=n;i++){
        setd(ndp);
        for(int j=0;j<9;j++){
            for(auto v : adj[j]){
                ll cs = nds[v][0] * gr[i][0] + nds[v][1] * gr[i][1] + nds[v][2] * gr[i][2];
                ndp[v] = max(ndp[v], dp[j] + cs);
            }
        }
        for(int j=0;j<9;j++) dp[j] = ndp[j];
    }
    cout << max({dp[2], dp[5], dp[6]}) << "\n";
    
}
