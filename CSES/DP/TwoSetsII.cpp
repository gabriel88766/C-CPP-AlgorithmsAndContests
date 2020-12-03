#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
int dp[250000], aux[250000];

typedef long long int ll;

ll mulmod(ll a, ll b, ll m = MOD) {
  ll r=0;
  for (a %= m; b; b>>=1, a=(a*2)%m) if (b&1) r=(r+a)%m;
  return r;
}


// Fast exponential
ll fexp(ll a, ll b, ll m = MOD) {
  ll r=1;
  for (a %= m; b; b>>=1, a=(a*a)%m) if (b&1) r=(r*a)%m; //mulmod for a  > 2e9
  return r;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int n, aux2;
    cin >> n;
    aux2 = (n*(n+1))/2;
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=aux2;j++){
            aux[j] = dp[j-i];
        }
        for(int j=i;j<=aux2;j++){
            dp[j] += aux[j];
            if(dp[j]>=MOD) dp[j] -= MOD;
            aux[j] = 0;
        }
    }
    int result = dp[aux2/2];
    int aux3 = fexp(2,MOD-2);
    result = mulmod(result,aux3);
    if(!(aux2%2)) cout << result;
    else cout << 0;

}
