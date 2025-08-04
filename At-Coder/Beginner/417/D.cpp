#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[10002][1001];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<tuple<int, int, int>> vx(n+1);
    for(int i=1;i<=n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        vx[i] = {a, b, c};
    }
    for(int j=1;j<=1000;j++) dp[n+1][j] = j;
    vector<ll> ps(n+1);
    for(int i=n;i>=1;i--){
        auto [p, a, b] = vx[i];
        ps[i] = b;
        for(int j=0;j<=1000;j++){
            if(j <= p){
                dp[i][j] = dp[i+1][j + a];
            }else{
                dp[i][j] = dp[i+1][max(0, j-b)];
            }
        }
    }
    for(int i=1;i<=n;i++) ps[i] += ps[i-1];
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int x;
        cin >> x;
        int k = 0;
        for(int j=n;j>=1;j>>=1){
            while(k + j <= n && x - ps[k+j] >= 500) k += j;
        }
        // cout << x-ps[k] << " " << x << " " << k << " " << ps[k] << endl;
        assert((x - ps[k] >= 500 || k == 0) && (x - ps[k] <= 1000 || k == n));
        if(k == n) cout << x - ps[k] << "\n";
        else cout << dp[k+1][x-ps[k]] << "\n";
    }
}
