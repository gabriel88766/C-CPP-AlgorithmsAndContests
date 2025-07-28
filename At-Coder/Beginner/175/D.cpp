#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
int p[30][N], ivp[N];
ll c[N];
ll cst[30][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> p[0][i];
        ivp[p[0][i]] = i;
    }
    ll ans = -INF_LL;
    for(int i=1;i<=n;i++){
        cin >> c[i];
        ans = max(ans, c[i]);
    }
    for(int i=1;i<=n;i++){
        cst[0][i] = c[p[0][i]];
    }
    for(int i=1;i<30;i++){
        for(int j=1;j<=n;j++){
            p[i][j] = p[i-1][p[i-1][j]];
            cst[i][j] = cst[i-1][j] + cst[i-1][p[i-1][j]];
        }
    }
    
    //case cycle is positive.
    for(int i=1;i<=n;i++){
        int x = i;
        ll cur = 0;
        for(int j=0;j<30;j++){
            if(k & (1 << j)){
                cur += cst[j][x];
                x = p[j][x];
            }
        }
        ans = max(ans, cur);
        for(int j=1;j<=min(k-1, n);j++){
            cur -= c[x];
            ans = max(ans, cur);
            x = ivp[x];
        }
    }
    //case cycle is negative
    for(int i=1;i<=n;i++){
        int x = i;
        ll cur = 0;
        for(int j=1;j<=min(k, n);j++){
            x = p[0][x];
            cur += c[x];
            ans = max(ans, cur);
        }
    }
    cout << ans << "\n";
}
