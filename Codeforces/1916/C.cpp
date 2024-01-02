#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[100005][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[1][0] = dp[1][1] = 1;
    for(int i=2;i<=100000;i++){
        dp[i][0] = dp[i-2][1];
        dp[i][1] = dp[i-1][0] + 1;
    }
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int c1 = 0;
        ll sum = 0;
        for(int i=0;i<n;i++){
            sum += v[i];
            if(v[i] % 2) c1++;
            if(i != 0) cout << sum - dp[c1][0] << " ";
            else cout << sum << " ";
        }
        cout << "\n";
    }
}
