#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//sf(n)  =  (s(f conv g)(n) - sum[i=2:n](sf(n/i) * g(i))) /g(1)
//example f(i) = phi(i), phi conv I = Id, sum Id is easy to calculate, sum of I is too
unordered_map<ll, __int128> dp[128];

__int128 calcconv(ll n){
    //something easy to calculate
    __int128 n1 = n % 2 ? n : n/2;
    __int128 n2 = n % 2 ? (n+1)/2 : n+1;
    return n1*n2;
}

ll ctt = 0;
__int128 calcsum(ll n){
    if(dp[0].count(n)) return dp[0][n];
    __int128 ans = calcconv(n);
    //ll g1 = 1; //ignore in this case
    ll fv = 2;
    while(fv <= n){
        ll lv = n/(n / fv);
        //sum of g from fv to lv . In this case = lv - fv + 1
        if(!dp[0].count(n/lv)) calcsum(n/lv);
        ans -= (lv - fv + 1) * dp[0][n/lv]; 
        fv = lv+1;
    }
    //g(i) = 1, no need to divide
    return dp[0][n] = ans;
}

vector<int> ps = {2, 3, 5, 7, 11, 13, 17};
vector<__int128> num(128, 1);

const int N = 1e6+1;
const ll MAX = 1e11;
const int X = 3e5;

__int128 phi[N];
void euler(){
    for(ll i=1;i<N;i++) phi[i] = i;
    for(ll i=2; i < N; i++){
        if(phi[i] == i){
            for(ll j = i; j < N; j += i){
                phi[j] -= phi[j]/i; 
            }
        }
    }
    for(int i=(1 << 7)-1;i>=0;i--){
        for(int k=0;k<7;k++){
            if(i & (1 << k)) num[i] *= ps[k];
        }
    }
}

const ll x = 1e18;

//sum phi(num[msk]*i), from i = 1 to m
__int128 calc(__int128 m, int msk){
    if(msk == 0) return dp[msk][m] = calcsum(m);
    if(dp[msk].count(m)) return dp[msk][m];
    __int128 ans = 0;
    for(int i=0;i<=127;i++){
        if((i | msk) != msk) continue;
        __int128 d = num[i];
        __int128 cur = 0;
        for(int j=0;j<=127;j++){
            if((j | msk) != msk) continue;
            if((j & i) == i){
                if(__builtin_popcount(j^i) % 2) cur -= calc(m/num[j], j);
                else cur += calc(m/num[j], j);
            }
        }
        ans += (cur*d)/phi[d];
    }
    ans *= phi[num[msk]];
    return dp[msk][m] = ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    euler();
    __int128 ans = 0;
    for(int j=127;j>=0;j--){
        ll rn = num[j];
        for(int i=1;i<=X;i++){
            dp[j][i] = dp[j][i-1];
            __int128 d = gcd(i, rn);
            __int128 aux = ((phi[rn]*phi[i])/phi[d])*d;
            dp[j][i] += aux;
        }
    }
    ans = calc(MAX, 127);
    ll res = ans % x;
    cout << res << "\n";

}        
 