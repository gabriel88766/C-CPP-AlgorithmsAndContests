#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

double dp[1 << 18][18];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> vp;
    vp.push_back({0, 0});
    n++;
    int msk = 0, msk2;
    for(int i=n;i<n+m;i++) msk |= (1 << i);
    msk2 = 1 << (n+m);
    msk2 -= 1;
    msk2 ^= msk;
    for(int i=1;i<n+m;i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    for(int i=0;i<(1 << (n+m));i++){
        for(int j=0;j<n+m;j++){
            dp[i][j] = 1e100;
        }
    }
    double ans = 1e100;
    auto dist = [&](int a, int b){
        return sqrt(pow(abs(vp[a].first - vp[b].first), 2) + pow(abs(vp[a].second - vp[b].second), 2));
    };
    for(int i=1;i< (1 << (n+m)); i++){
        if(__builtin_popcount(i) == 1){
            dp[i][__builtin_ctz(i)] = dist(0, __builtin_ctz(i));
        }
        double vel = 1 << __builtin_popcount(i & msk);
        for(int j=0;j<n+m;j++){
            if(i & (1 << j)){
                for(int k=0;k<n+m;k++){
                    if(!(i & (1 << k))){
                        dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + dist(j, k)/vel);
                    }
                }
            }
        }
        
        if((i & msk2) == msk2){
            ans = min(ans, dp[i][0]);
        }
    }
    cout << fixed << setprecision(8) << ans << "\n";
}
