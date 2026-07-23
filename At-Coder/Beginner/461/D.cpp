#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int sum[505][505];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, k;
    cin >> h >> w >> k;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            char c;
            cin >> c;
            sum[i][j] = c - '0';
            sum[i][j] += sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
        }
    }
    //must be O(N + M) for each cell, calc less than k
    auto calcLs = [&](int n, int m, int k){
        int ci = n;
        int ans = 0;
        for(int j = 0; j < m; j++){
            while(ci > 0 && sum[n][m] - sum[ci-1][m] - sum[n][j] + sum[ci-1][j] < k) ci--;
            ans += n - ci;
        }
        return ans;
    };
    ll ans = 0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            ans += calcLs(i, j, k+1) - calcLs(i, j, k);
        }
    }
    cout << ans << "\n";
}
