#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<ll>> comp(vector<vector<ll>>  a, vector<vector<ll>> b){
    int n = a.size() - 1;
    vector<vector<ll>> ans(n+1, vector<ll>(n+1, INF_LL));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                ans[i][k] = min(ans[i][k], a[i][j] + b[j][k]);
            }
        }
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> c(n+1, vector<ll>(n+1)), ans(n+1, vector<ll>(n+1, INF_LL));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> c[i][j];
        }
        ans[i][i] = 0;
    }
    k-=1;
    auto old = c;
    while(k){
        if(k & 1){
            ans = comp(ans, c);
        }
        c = comp(c, c);
        k >>= 1;
    }
    for(int i=1;i<=n;i++){
        ll cur = INF_LL;
        for(int j=1;j<=n;j++){
            cur = min(cur, ans[i][j] + old[j][i]);
        }
        cout << cur << "\n";
    }


}
