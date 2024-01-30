#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


ull mult(ull a, ull  b, ull  m){
    __int128 res = (unsigned __int128)a * b % m;
    return (ull)res;
}

ull binpow(ull a, ull b, ull m){
    a %= m;
    ull ans = 1;
    while(b){
        if(b & 1) ans = mult(ans, a, m);
        a = mult(a, a, m);
        b >>= 1;
    }
    return ans;
}

bool check_composite(ull n, ull a, ull d, int s){
    ull res = binpow(a, d, n);
    if(res == 1 || res == (n-1)) return false;
    for(int r=1;r<s;r++){
        res = mult(res, res, n);
        if(res == (n-1)) return false;
    }
    return true;
}

bool isPrime(ull n){
    if(n < 2) return false;
    int s = 0;
    ull d = n - 1;
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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test
    ll n, p;
    cin >> n >> p;
    vector<ll> ds;
    vector<ll> f;
    ll x = p - 1;
    for(ll i=1;i*i<=x;i++){
        if(!(x % i)){
            ds.push_back(i);
            if(i*i != x) ds.push_back(x/i);
        }
    }
    sort(ds.begin(), ds.end());
    for(auto x : ds){
        if(isPrime(x)) f.push_back(x);
    }
    ll qt1 = 0;
    ll ans = 0;
    vector<ll> v(n);
    unordered_map<ll, ll> mp;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(v[i] == 1) mp[1]++;
        else{
            ll md = p-1;
            for(auto x : f){
                while(!(md % x) && binpow(v[i], md/x, p) == 1){
                    md = md/x;
                }
            }
            mp[md]++;
        }
    }
    for(auto x : ds){
        for(auto y : ds){
            if(y >= x && !(y % x)){
                ans += mp[x] * mp[y];
            }
        }
    }
    cout << ans << "\n";
}
