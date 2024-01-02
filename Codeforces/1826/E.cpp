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
    int m, n;
    cin >> m >> n;
    vector<ll> pf(n);
    for(int i=0;i<n;i++) cin >> pf[i];
    vector<int> ord;
    for(int i=0;i<n;i++) ord.push_back(i);
    vector<vector<int>> rt(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> rt[i][j];
        }
    }
    sort(ord.begin(), ord.end(), [&](int u, int v){
        return rt[0][u] < rt[0][v];
    });
    vector<ll> dp(n, 0);
    for(int i=0;i<n;i++){
        int x = ord[i];
        //dp[i]?
    }

    ll ans = 0;
    for(int i=0;i<n;i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
}


//UNSOLVED