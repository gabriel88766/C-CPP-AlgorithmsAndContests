#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll dp[3][N][8];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n);
    string s;
    for(int i=0;i<n;i++) cin >> v[i];
    cin >> s;
    ll ans = 0;
    //first M
    vector<int> cnt(8, 0);
    for(int i=0;i<n;i++){
        if(s[i] == 'M') cnt[1 << v[i]]++;
        for(int j=0;j<8;j++) dp[0][i][j] = cnt[j];
    }
    //now E
    for(int i=0;i<n;i++){
        if(i != 0){
            for(int j=0;j<8;j++){
                dp[1][i][j] += dp[1][i-1][j];
            }
        }
        if(s[i] == 'E'){
            int x = 1 << v[i];
            for(int j=0;j<8;j++){
                dp[1][i][j | x] += dp[0][i][j];
            }
        }
    }
    //finally X
    for(int i=0;i<n;i++){
        if(s[i] == 'X'){
            int x = 1 << v[i];
            for(int j=0;j<8;j++){
                dp[2][i][j | x] += dp[1][i][j];
            }
            for(int j=0;j<8;j++){
                for(int u=0;;u++){
                    if(j & (1 << u)) continue;
                    else{
                        ans += dp[2][i][j] * u;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}
