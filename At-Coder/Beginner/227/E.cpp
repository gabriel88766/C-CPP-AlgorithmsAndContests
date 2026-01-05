#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[31][501][31][31];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    int a = 0, b = 0;
    for(auto c : s){
        if(c == 'K') a++;
        if(c == 'E') b++;
    }
    int c = n - a - b; //"KEY"
    s = " " + s;
    dp[0][0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 500; j++){
            for(int qa = 0; qa <= min(a, i-1); qa++){
                for(int qb = 0; qa + qb <= i-1 && qb <= b; qb++){
                    if(dp[i-1][j][qa][qb] == 0) continue;
                    int xa = 0, xb = 0, xc = 0;
                    int qc = i - 1 - qa - qb;
                    int fa = -1, fb = -1, fc = -1, cnt = 0;
                    for(auto c : s){
                        if(c == 'K'){
                            if(xa != qa) xa++;
                            else {
                                if(fa == -1) fa = cnt;
                                cnt++;
                            }
                        }
                        if(c == 'E'){
                            if(xb != qb) xb++;
                            else{
                                if(fb == -1) fb = cnt;
                                cnt++;
                            }
                        }
                        if(c == 'Y'){
                            if(xc != qc) xc++;
                            else{
                                if(fc == -1) fc = cnt;
                                cnt++;
                            }
                        }
                    }
                    if(fa != -1){
                        dp[i][j + fa][qa+1][qb] += dp[i-1][j][qa][qb]; 
                    }
                    if(fb != -1){
                        dp[i][j + fb][qa][qb+1] += dp[i-1][j][qa][qb];
                    }
                    if(fc != -1){
                        dp[i][j + fc][qa][qb] += dp[i-1][j][qa][qb];
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(int j=0;j<=min(500, k); j++) ans += dp[n][j][a][b];
    cout << ans << "\n";
}   
