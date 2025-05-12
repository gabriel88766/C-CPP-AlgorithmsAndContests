#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int lp[100'000'001]; //lowest prime that divides i
vector<int> pr;

ll binpow(ll a, ll b, ll m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

vector<int> g2 = {1};
vector<int> g6 = {1, 5};
vector<int> g10 = {1, 3, 7, 9};
vector<int> g30 = {1, 7, 11, 13, 17, 19, 23, 29};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //FOR EACH PRIME lower than p <= 10^8, count how many n <= 10^11 such that n^15 \equiv -1 mod p
    const ll N = 1e8; //1e8
    const ll M = 1e11; //1e11
    __int128 ans = 0;
    ans += ((M+1)/2)*2;
    for (ll i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
            //now need to know if there are any x^15 == -1 mod p such that x <= i;
            //order 2 => x^15 == -1.
            //order 6 => x^15 == -1.
            //order 10 => x^15 == -1.
            //order 30 => x^15 == -1.
            //there are any other order? I guess not.
            //find for each prime found which are for each order, there are not that many.
            //find a primitive root first then make pr^(p-1)/30, pr^2*(p-1)/30, etc...
            //ALGO to find primitive root is bruteforcing.. try all pr^(p-1)/x, where x is 
            //a prime factor of p-1, if pr^(p-1)/x == 1 mod p then pr is not primitive root
            vector<ll> pf;
            ll num = i-1;
            while(num != 1){
                if(pf.size() == 0 || pf.back() != lp[num]) pf.push_back(lp[num]);
                num /= lp[num];
            }
            ll prt = -1;
            for(ll j=1;j<i;j++){
                bool ok = true;
                for(auto &x : pf){
                    if(binpow(j, (i-1)/x, i) == 1) ok = false;
                }
                if(ok){
                    prt = j;
                    break;
                }
            }
            if(i == 2) cout << prt << "\n";
            //found primitive root...
            if((i-1) % 2 == 0){ //almost always..
                for(auto j : g2){
                    // if(gcd(2, j) != 1) continue;
                    ll val = binpow(prt, j*(i-1)/2, i);
                    ll qnt = (M + i - val) / i;
                    ans += qnt * i;
                }
            }
            if((i-1) % 6 == 0){
                for(auto j : g6){
                    // if(gcd(6, j) != 1) continue;
                    ll val = binpow(prt, j*(i-1)/6, i);
                    ll qnt = (M + i - val) / i;
                    ans += qnt * i;
                }
            }
            if((i-1) % 10 == 0){
                for(auto j : g10){
                    // if(gcd(10, j) != 1) continue;
                    ll val = binpow(prt, j*(i-1)/10, i);
                    ll qnt = (M + i - val) / i;
                    ans += qnt * i;
                }
            }
            if((i-1) % 30 == 0){
                for(auto j : g30){
                    // if(gcd(j, 30) != 1) continue;
                    ll val = binpow(prt, j*(i-1)/30, i);
                    ll qnt = (M + i - val) / i;
                    ans += qnt * i;
                }
            }
        }
        for (ll j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
            
            
    }
    ll xx = 1e18;
    ll hi = ans / xx, lo = ans % xx; 
    cout << hi << " " << lo << "\n";
}
