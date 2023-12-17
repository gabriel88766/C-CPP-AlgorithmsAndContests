#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<int>> vx(1001);
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<=1000;i++){
        int cur = i;
        for(int j=1;cur;j*=2){
            assert(!(cur % j));
            cur -= j;
            vx[i].push_back(j);
            if((cur % (2 * j))){
                vx[i].push_back(j);
                cur -= j;
            }
        }
    }
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n), cp(n);
    for(int i=0;i<n;i++) cin >> h[i];
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++) cin >> cp[i];
    vector<int> dp(x+1, 0);
    for(int i=0;i<n;i++){
        for(auto j : vx[cp[i]]){
            for(int k = x; k >= j*h[i]; k--){
                dp[k] = max(dp[k], dp[k-j*h[i]] + j*s[i]);
            }
        }
    }
    cout << dp[x] << "\n";

}
