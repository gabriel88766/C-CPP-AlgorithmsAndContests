#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1 << 20;
const int M = 20;

int t[M][M];
int dp[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    string s;
    cin >> n >> m >> s;
    for(int i=1;i<n;i++){
        int a = s[i] - 'a';
        int b = s[i-1] - 'a';
        if(b != a) t[a][b]++, t[b][a]++;
    }
    memset(dp, 63, sizeof(dp));
    dp[0] = 0;
    //crazy wrong solution :) or maybe not
    for(int i=0;i<(1 << m);i++){
        int ord = __builtin_popcount(i);
        for(int j=0;j<m;j++){
            if(!(i & (1 << j))){
                int sum = 0;
                for(int k=0;k<m;k++){
                    if(k == j) continue;
                    if(i & (1 << k)) sum += t[j][k] * ord;
                    else sum -= t[j][k] * ord;
                }
                dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + sum);
            }
        }
    }
    cout << dp[(1 << m) - 1] << "\n";
}   