#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1 << 20;
bool pos[N];
int dp[N]; //greatest length which is a submask of x
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        int cm = 0;
        for(int j=i;j<s.size();j++){
            int cb = 1 << (s[j] - 'a');
            if(cm & cb) break;
            cm |= cb;
            pos[cm] = true;
        }
    }
    for(int i=0;i<(1 << 20);i++){
        if(pos[i]){
            dp[i] = __builtin_popcount(i);
        }
    }
    for(int i=1;i<(1 << 20);i++){
        for(int j=0;j<20;j++){
            if(i & (1 << j)){
                dp[i] = max(dp[i], dp[i ^ (1 << j)]);
            }
        }
    }
    int ans = 0;
    int msk = (1 << 20) - 1;
    for(int i=1;i<(1 << 20);i++){
        if(pos[i]){
            int cur = __builtin_popcount(i) + dp[msk ^ i];
            ans = max(ans, cur);
        }
    }
    cout << ans << "\n";
}
