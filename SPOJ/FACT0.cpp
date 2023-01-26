#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//factoring in O(N^1/4 logN) + O(log^3(N)) (of miler rabin)
//begin miller rabin:
void binmul(ll &a, ll  b, ll  m){
    a %= m;
    ll ans = 0;
    while(b){
        if(b & 1){
            ans += a;
            if(ans > m) ans -= m;
        }
        a += a;
        if(a > m) a -= m;
        b >>= 1;
    }
    a = ans;
}

ll binpow(ll a, ll b, ll m){
    a %= m;
    ll ans = 1;
    while(b){
        if(b & 1) binmul(ans, a, m);
        binmul(a, a, m);
        b >>= 1;
    }
    return ans;
}

bool check_composite(ll n, ll a, ll d, int s){
    ll res = binpow(a, d, n);
    if(res == 1 || res == (n-1)) return false;
    for(int r=1;r<s;r++){
        binmul(res, res, n);
        if(res == (n-1)) return false;
    }
    return true;
}

bool isPrime(ll n){
    if(n < 2) return false;
    int s = 0;
    ll d = n - 1;
    while(!(d & 1)){
        d >>= 1;
        s++;
    }
    for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if (n == a) return true;
        if(check_composite(n,a,d,s)) return false;
    }
    return true;
}
//end miler rabin

//begin pollard rho finds 
ll gcd(ll a, ll b){
    while(b){
        ll c = a % b;
        a = b;
        b = c;
    }
    return a;
}
ll funct(ll x, ll c, ll mod){
    binmul(x,x,mod);
    x += c;
    return x > mod ? x - mod : x;
}
ll rho(ll n, ll x0=2, ll c = 1){//if returned n, change c or/and x0 idk..
    if(!(n&1)) return 2;
    ll x = x0, y = x0;
    ll g = 1;
    while(g == 1){
        x = funct(x,c,n);
        y = funct(y,c,n);
        y = funct(y,c,n);
        g = gcd(abs(x-y), n);
    }
    if(g == n) return rho(g, x0, c+1);
    return isPrime(g) ? g : rho(g, x0, c);
}

vector<pair<ll,ll>> fact(ll n){
    vector<pair<ll,ll>> f;
    while(n != 1){
        if(isPrime(n)){
            f.push_back({n, 1});
            n = 1;
        }else{
            ll cur = rho(n);
            ll cnt = 0;
            while(!(n % cur)){
                n /= cur;
                cnt++;
            }
            f.push_back({cur, cnt});
        }
    }
    sort(f.begin(),f.end());
    return f;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n;
    cin >> n;
    while(n){
        if(n == 1){
            cout << "1^1\n";
            cin >> n;
            continue;
        }
        auto u = fact(n);
        for(auto c : u){
            cout << c.first << "^" << c.second << " ";
        }
        cout << endl;
        cin >> n;
    }
}
