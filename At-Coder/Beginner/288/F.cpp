#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
const int N = 2e5+3;
ll dp[N];

void sum(string s){
    
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> n >> s;
    dp[n+1] = 0;
    ll aux = 1;
    for(int i=n;i>=1;i--){
        dp[i] = ((s[i-1]-'0')*aux + dp[i+1]) % MOD;
        aux = (aux * 10) % MOD;
        aux = (aux + dp[i]) % MOD;
    }
    cout << dp[1];
}
 