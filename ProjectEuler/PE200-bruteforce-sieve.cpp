#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//bounds not fixed, guess ~ 10^16; 
// we need 200th number, odds should be less than 1/5000 or something??
// why? because 1/1000 should have 200 and 1/5 should be prime-proof(optmistic because many are even??)?? total guess...
// so 5M numbers enough
// turns out, 85308 / 5798300 have "200"
// and 35997 / 85308 are prime-proof *O*


const int N = 4e7+1;
int p[N]; // 0 if prime, 1 if not prime
vector<ll> primes;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            primes.push_back(i);
        }
    }
}

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
    //freopen("in", "r", stdin); //test input
    sieve();
    vector<ll> cand, valid;  
    ll lim = 1e16;  
    for(auto p : primes){
        for(auto q : primes){
            if(lim/q < q*q) break; //q*q*q > lim
            if(p*p > lim / (q*q*q)) break;//p*p*q*q*q > lim
            if(p == q) continue;
            ll cur = p*p*q*q*q;
            assert(cur <= lim);
            string s = to_string(cur);
            bool ok = false;
            for(int i=0;i<s.size()-2;i++){
                if(s.substr(i, 3) == "200") ok = true;
            }
            if(!ok) continue;
            //need to be primeproof
            //trial division not ok, test miller rabin. ~85308 * ln²(n) * log10(n) * 10;
            cand.push_back(cur);
        }
    }
    sort(cand.begin(), cand.end());
    for(auto x : cand){
        string s = to_string(x);
        bool ok = true;
        for(int j=0;j<s.size();j++){
            for(char u='0'; u<='9';u++){
                if(j == 0 && u == '0') continue;
                string cur = s;
                cur[j] = u;
                if(isPrime(stoll(cur))){
                    ok = false;
                    break;
                }
            }

            if(!ok) break;
        }
        if(ok) valid.push_back(x);
    }
    int cnt = 0;
    for(auto x : valid) if(x % 2 == 0) cnt++;
    cout << cnt << "\n";
    cout << valid[199] << "\n";
}
