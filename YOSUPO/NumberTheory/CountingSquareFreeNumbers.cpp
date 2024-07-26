#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e7; //10^(20/3)

unordered_map<ll, ll> mp;
char p[N];
ll mi[N];
//mi
void init(ll n){
    //ll x = pow(n, 1/3.0);
    ll x = N-1;
    for(ll i=1;i<=x;i++) mi[i] = 1;
    for(ll i=2;i<=x;i++){
        if(!p[i]){
            for(ll j=i;j<=x;j+=i) {mi[j] *= -1; p[j] = 1;}
            for(ll j=i*i;j<=x;j+=(i*i)){
                mi[j] = 0;
            }
        }
    }
    mp[0] = 0;
    for(int i=1;i<=x;i++){
        mp[i] = (mp[i-1] + mi[i]);
    }
}
ll calcsum(ll n){
    //sum conv(n) - sum(2, n) sf(floor(n/d)) * g(d) 
    if(mp.count(n)) return mp[n];
    ll res = 1;
    ll cur = 2;
    while(cur <= n){
        ll curn = n/cur;
        ll mn = n/curn;
        if(!mp.count(curn)) mp[curn] = calcsum(curn);
        res -= (mp[curn]*((mn-cur+1)));
        cur = mn+1;
    }
    return mp[n] = res;
}

ll mysqrt(ll x){
    ll ans = 0;
    for(ll j = sqrt(x)+1; j >= 1; j >>= 1){
        while((ans + j)*(ans+j) <= x) ans += j;
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    cin >> n;
    init(n);
    ll fv = 1;
    ll ans = 0;
    ll cnt = 0;
    while(fv*fv <= n){
        cnt++;
        ll lv = mysqrt(n /(n / (fv * fv)));
        ans += (calcsum(lv) - calcsum(fv-1)) * (n/(fv*fv));
        fv = lv + 1;
    }
    cout << ans << "\n";
}
