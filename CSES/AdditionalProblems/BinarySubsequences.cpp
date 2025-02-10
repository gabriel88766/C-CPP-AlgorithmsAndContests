#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

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
    }
    ll ans = 0;
    for(int i=1;i<=n;i++) ans += dp[i];
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    // cin >> n;
    unordered_set<int> s;
    
    for(int k=1;k<=25;k++){
        for(int i=0;i<(1 << k);i++){
            string cur;
            for(int j=0;j<k;j++){
                if(i & (1 << j)) cur += '1';
                else cur += '0';
            }
            if(solve(cur) <= 1000000) s.insert(solve(cur));
        }
    }
    cout << s.size() << "\n";
}
