#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll pot[64];
ll pot3[64];

map<ll,ll> mp[64];

ll solve(ll n, int curpt){ //Recursive DP with memo
    if(2*(pot[curpt+1]-1) <= n) return pot3[curpt+1];
    if(curpt == 0){
        return n+1;
    }else{
        ll ans = 0;
        for(ll i=0;i<=2;i++){
            ll x = n - i*pot[curpt];
            if(x >= 0) {
                if(mp[curpt-1].count(x)) ans = (ans + mp[curpt-1][x]) % MOD;
                else {
                    mp[curpt-1][x] = solve(x, curpt-1);
                    ans = (ans + mp[curpt-1][x]) % MOD;
                }
            }
        }
        return ans;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    cin >> n;
    pot[0] = 1, pot3[0] = 1;
    for(int i=1;i<=62;i++){
        pot[i] = 2*pot[i-1];
        pot3[i] = (3*pot3[i-1]) % MOD;
    }
    cout << solve(n, 60);
}
 