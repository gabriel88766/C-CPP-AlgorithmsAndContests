#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    const int X = 1000;
    ll ans1 = 0, ans2 = 0, ans3 = 0;
    //Problem 1 : maximum pairing and.
    //perfect pairing:
    //1 2 5 6 9 10 13 14 17 18
    //0 3 4 7 8 11 12 15 16 19
    for(int i=0;i<10;i++){
        ll cnt = 0;
        for(int j=1;j<=X;j++){
            if(j & (1 << i)) cnt++;
        }
        ll tt = (cnt/2) * (cnt - cnt/2);
        ans1 += tt * (1 << i);
    }

    //Problem 2 : maximum xor sum; (dp problem)
    map<ll, vector<pair<int, int>>> mpx;
    for(int i=1;i<=X;i++){
        for(int j=i+1;j<=X;j++){
            int vxor = (i * i) ^ (j * j);
            mpx[vxor].push_back({i, j});
        }
    }
    vector<ll> dp(X + 1, 0);
    for(auto [k, v] : mpx){
        auto ndp = dp;
        for(auto [x, y] : v){
            ndp[y] = max(ndp[y], dp[x] + k);
            ndp[x] = max(ndp[x], dp[y] + k);
        }
        dp = ndp;
    }
    ans2 = *max_element(dp.begin(), dp.end());
    //Problem 3 : reachable NIM;
    for(int i=0;i<X;i++){
        for(int j=0;j<X;j++){
            for(int k=0;k<X;k++){
                int xorv = i ^ j ^ k;
                if(xorv == 0){
                    //xor is 0, so reachable?
                    //yes :)
                }else{
                    //xor isn't 0, so reachable?
                    //No, unless there is some u > i (i ^ j ^ k  == 0) or u > j ... or u > k ...
                    int x1 = i ^ j;
                    int x2 = i ^ k;
                    int x3 = j ^ k;
                    if(k < x1 || j < x2 || i < x3); //then ok;
                    else ans3++;
                }
            }
        }
    }
    vector<ll> ans(1001, 0);
    ans[0] = ans1;
    ans[1] = ans2;
    ans[2] = ans3;
    for(int i = 3; i <= 1000; i++){
        ans[i] = ((((ans[i-1]) * ans[i-2]) % MOD) * ans[i-3]) % MOD;
    }
    cout << ans[1000] << "\n";
}

