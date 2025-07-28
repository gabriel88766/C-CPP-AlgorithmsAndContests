#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4;i<N;i++){
        dp[i] = i/2 + dp[i-4];
        // if(i <= 10) cout << i << " " << dp[i] << "\n";
    }
    int t;
    cin >> t;
    while(t--){
        ll ans = 0, x = 0, y = 0, n;
        string ss;
        string s;
        cin >> n >> s;
        for(auto c : s){
            if(c == 'B') ans += y; //pairs of pp that must go to end
            if(c == 'P') x++; //number of p's that are not "pp"
            if(ss.size() && ss.back() == c){
                if(c == 'B'){
                    ans += x;
                }else{
                    y++;
                    x-=2;
                }
                ss.pop_back();
            }else{
                ss += c;
            }
        }
        if(ss.size() && ss[0] == 'B') ss = ss.substr(1, ss.size() - 1);
        ans += dp[ss.size()];
        cout << ans << "\n";
    }
}
