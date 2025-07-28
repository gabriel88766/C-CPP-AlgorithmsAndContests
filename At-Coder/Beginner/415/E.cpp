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
    int h, w;
    cin >> h >> w;
    vector<vector<ll>> gr(h+1, vector<ll>(w+1));
    vector<vector<ll>> dp(h+1, vector<ll>(w+1));
    vector<ll> px(h+w+2);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
        }
    }
    auto clear = [&](){
        for(int i=0;i<=h;i++){
            fill(dp[i].begin(), dp[i].end(), -INF_LL);
        }
    };
    for(int i=2;i<=h+w;i++){
        cin >> px[i];
    }
    ll lo = 0, hi = 3e14;
    while(lo != hi){
        ll mid = lo + (hi - lo)/2;
        clear();
        dp[0][1] = mid;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(dp[i-1][j] + gr[i][j] - px[i+j] >= 0){
                    dp[i][j] = max(dp[i][j], dp[i-1][j] + gr[i][j] - px[i+j]);
                }
                if(dp[i][j-1] + gr[i][j] - px[i+j] >= 0){
                    dp[i][j] = max(dp[i][j], dp[i][j-1] + gr[i][j] - px[i+j]);
                }
            }
        } 
        if(dp[h][w] != -INF_LL) hi = mid;
        else lo = mid + 1;
    } 
    cout << lo << "\n";
}
