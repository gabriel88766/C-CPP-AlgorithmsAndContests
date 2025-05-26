#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
int has[N];

ll solve(string s){
    int n = s.size();
    vector<ll> dp(s.size() + 1);
    s = " " + s;
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=0;j--){
            dp[i] += dp[j];
            if(s[i] == s[j]) break;
        }
        if(dp[i] >= 1000000) break;
    }
    ll ans = 0;
    for(int i=1;i<=n;i++) ans += dp[i];
    return ans;
}
void test(const string &s){
    if(s.size() >= 26) return;
    ll tt = solve(s);
    if(tt > 1000000){
        return;
    }else{
        if(has[tt] == false || has[tt] > s.size()) has[tt] = s.size();
    }
    test(s + '0');
    test(s + '1');
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    // cin >> n;
    cout << solve("10101010 10101 01010 10101 01010") << "\n";
    // test("0");
    // int sz = 0;
    // for(int i=1;i<=1000000;i++) if(has[i]) sz++;
    // cout << sz << "\n"; //will print 1000000, but I need over 2 min to check all these 2^29 binary strings(yeah half because I cut all mirrored)
}
