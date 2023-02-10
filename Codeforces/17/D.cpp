#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll mod(string s, ll mod){
    int bp = 0;
    int n = s.size();
    ll rem = 0;
    while(bp < n){
        rem *= 10;
        rem += (s[bp++]-'0');
        if(rem < mod) continue;
        else rem = rem % mod;
    }
    return rem;
}

ll binpow(ll a, ll  b, ll  m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string b, n;
    ll c, aux, aux2, d;
    cin >> b >> n >> c;
    
    if(n == "1"){
        ll ans = mod(b, c);
        ans -= 1;
        if(ans <= 0) ans += c;
        cout << ans;
        return 0;
    }else if(c == 1){
        cout << 1;
        return 0;
    }

    aux = mod(b, c);
    d = aux-1;
    if(d<0) d += c;

    vector<ll> facts;
    aux2 = c;
    for(int i=2;i<=100000;i++){
        if(i > aux2) break;
        if(!(aux2%i)){
            facts.push_back(i);
            while(!(aux2%i)) aux2 /= i;
        } 
    }
    if(aux2 > 1) facts.push_back(aux2);

    ll phi = c;
    for(auto u : facts){
        phi /= u;
        phi *= (u-1);
    }

    ll res;
    if(n.size() < 10){
        res = binpow(aux, mod(n,10000000000) - 1, c) * d;
        res = res % c;
    }else{
        res = binpow(aux, mod(n,phi) + phi - 1, c) * d;
        res = res % c;
    }
    if(res == 0) res = c;
    cout << res;
}
