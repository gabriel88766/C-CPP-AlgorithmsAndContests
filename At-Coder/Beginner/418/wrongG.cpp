#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp1[200005], dp2[200005], dp3[200005], dp4[200005];
void inv(string &s){
    for(auto &c : s){
        c ^= 1;
    }
}
void rev(string &s){
    reverse(s.begin(), s.end());
}
pair<ll, ll> ans[16];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    string s;
    cin >> n >> s;
    auto solve = [&](int a, int b, int c, int d, int x){
        for(int i=n-1;i>=0;i--){
            if(i == n-1){
                if(s[i] == '0'){
                    dp3[i] = dp4[i] = 1;
                    dp1[i] = 0;
                    dp2[i] = -INF_INT;
                }else{
                    dp1[i] = dp2[i] = 1;
                    dp3[i] =  0;
                    dp4[i] = -INF_INT;
                }
            }else{
                dp1[i] = dp2[i] = dp3[i] = dp4[i] = 0;
                if(s[i] == '0') dp4[i] = 1, dp2[i] = -INF_INT, dp3[i] = 1;
                else dp2[i] = 1, dp4[i] = -INF_INT, dp1[i] = 1;
                int x , y;
                if(s[i] == '0'){
                    x = a;
                    y = b;
                }else{
                    x = c;
                    y = d;
                }
                if(x == 0){
                    dp3[i] += dp3[i+1];
                    dp4[i] = max(dp4[i], dp4[i+1] + 1);
                }else{
                    dp1[i] += dp3[i+1];
                    dp2[i] = max(dp2[i], dp4[i+1] + 1);
                }
                if(y == 0){
                    dp3[i] += dp1[i+1];
                    dp4[i] = max(dp4[i], dp2[i+1] + 1); 
                }else{
                    dp1[i] += dp1[i+1];
                    dp2[i] = max(dp2[i], dp2[i+1] + 1);
                }
            }
        }
        int ans = -1;
        ll tt = 0;
        if(x == 1){
            for(int i=0;i<n;i++) ans = max(ans, dp2[i]);
            for(int i=0;i<n;i++) tt += dp1[i];
        }else{
            for(int i=0;i<n;i++) ans = max(ans, dp4[i]);
            for(int i=0;i<n;i++) tt += dp3[i];
        }
        return make_pair(ans, tt);
    };
    //correct for
    //0, 1, 3, 5, 6, 7, 9, 13, 15 
    //0000 cte
    //0001 AND //solve 
    //0011 = 7gpt
    //0101 = 8gpt
    //0110 XOR
    //0111 OR
    //1001 XNOR
    /////////////1101 MISSING 0010. solve 0100 reverse
    //1111 cte
    //0000
    ans[0] = solve(0, 0, 0, 0, 1);
    ans[1] = solve(0, 0, 0, 1, 1);
    ans[3] = solve(0, 0, 1, 1, 1);
    ans[5] = solve(0, 1, 0, 1, 1);
    ans[6] = solve(0, 1, 1, 0, 1);
    ans[7] = solve(0, 1, 1, 1, 1);
    ans[9] = solve(1, 0, 0, 1, 1);
    ans[15] = solve(1, 1, 1, 1, 1);
    //0010
    inv(s);
    ans[8] = solve(0, 0, 0, 1, 1);

    for(int i=0;i<=15;i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}
