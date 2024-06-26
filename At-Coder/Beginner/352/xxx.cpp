#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;//1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


typedef long long int ll;
ll mult(ll a, ll  b, ll  mod){
    __int128 res = (__int128)a * b % mod;
    return (ll)res;
}

ll binpow(ll a, ll b, ll mod){
    if(b == 0) return 1;
    if(b == 1) return a % mod;
    ll aux = binpow(a, b/2, mod);
    if(b & 1) return mult(mult(aux, aux, mod), a, mod);
    else return mult(aux, aux, mod);
}

bool check_composite(ll n, ll a, ll d, int s){
    ull res = binpow(a, d, n); // a^d
    if(res == 1 || res == (n-1)) return false;
    for(int r=1;r<s;r++){
        res = mult(res, res, n);
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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    Solution s;
    cout << s.countPrimes(336);
}
