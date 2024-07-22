#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const double PI = acos(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e6; //10^(20/3)

//retruns sf*g(n) 
ll conv(ll n){
    ll n1 = n % 2 ? n : n/2;
    ll n2 = (n+1) % 2 ? n+1 : (n+1)/2;
    return ((n1%MOD) * (n2%MOD))%MOD;
}

unordered_map<ll, ll> mp;
char p[N];
ll phi[N];
//totient
void init(ll n){
    ll x = pow(n, 2/3.0);
    for(int i=1;i<=x;i++) phi[i] = i;
    for(int i=2;i<=x;i++){
        if(!p[i]){
            for(int j=i;j<=x;j+=i){
                phi[j] -= phi[j]/i;
                p[j] = 1;
            }
        }
    }
    mp[1] = 1;
    for(int i=2;i<=x;i++){
        mp[i] = (mp[i-1] + phi[i]) % MOD;
    }
}
ll calcsum(ll n){
    //conv(n) - sum(2, n) sf(floor(n/d)) * g(d) 
    ll res = conv(n);
    ll cur = 2;
    while(cur <= n){
        ll curn = n/cur;
        ll mn = n/curn;
        if(!mp.count(curn)) mp[curn] = calcsum(curn);
        res = (res - (mp[curn]*((mn-cur+1)%MOD))%MOD)%MOD;
        if(res < 0) res += MOD;
        cur = mn+1;
    }
    return mp[n] = res;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    cin >> n;
    init(n);
    cout << calcsum(n);
}
