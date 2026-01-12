#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int a[N], dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    int mx = 0;
    memset(dp, 0xFF, sizeof(dp));
    dp[0] = INF_INT;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        int j = 0;
        for(int jmp = n/2;jmp>=1;jmp>>=1){
            while(j + jmp <= n && dp[j + jmp] >= a[i]) j += jmp;
        }
        dp[j+1] = a[i];
        mx = max(mx, j+1);
        // cout << j+1 << "\n";
    }
    cout << mx << "\n";
}   
