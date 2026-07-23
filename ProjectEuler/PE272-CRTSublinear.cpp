#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 10000000;
int lp[N+1];
vector<ll> p;
void sieve(){
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            p.push_back(i);
        }
        for (int j = 0; i * p[j] <= N; ++j) {
            lp[i * p[j]] = p[j];
            if (p[j] == lp[i]) {
                break;
            }
        }
    }
}

ll binpow(ll a, ll b, ll m){
    a %= m;
    ll ans = 1;
    while(b){
        if(b & 1) ans = (a * ans) % m;
        a = (a*a) % m;
        b >>= 1;
    }
    return ans;
}


int legendrex(ll a, ll p){
    a %= p;
    if(a < 0) a += p;
    ll val = binpow(a, (p-1)/2, p);
    return val > 1 ? -1 : val;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //n <= 10^11 and C(n) = 242 = 3^5 - 1
    //if x³ == 1 mod p has 3 roots, then x³ == 1 mod p^k has 3 roots for any prime p != 3
    //for p = 2^k, there is only 1 root :)
    //for p = 3, 1 only root, for p = 3^k has 3 roots (hard to prove)
    //fpr p >= 5, hansel lemma... if -3 is quadratic residue mod p, then it is mod p^k and has 2 roots too.
    //because 7 * 9 * 13 * 19 = 15561, then must sieve up to 10^11 / 15561 :)
    sieve();
    ll X = 1e11;
    //Cases, n = x, n = 3x, n = 9x
    vector<ll> p2, fr;
    for(auto x : p){
        if(x > 3 && legendrex(x-3, x) == 1) p2.push_back(x);
        else if(x != 3) fr.push_back(x); 
    }
    //#case 1 and 2.
    ull ans = 0;
    for(int i = 0; i < p2.size(); i++){
        if(p2[i] * p2[i] > (((X / p2[i]) / p2[i]) / p2[i])) break;
        for(int j = i + 1; j < p2.size(); j++){
            if(p2[i] * p2[j] > (((X / p2[j]) / p2[j]) / p2[j])) break;
            for(int k = j + 1; k < p2.size(); k++){
                if(p2[i] * p2[j] > (((X / p2[k]) / p2[k]) / p2[k])) break;
                for(int w = k + 1; w < p2.size(); w++){
                    if(p2[i] * p2[j] > (((X / p2[k]) / p2[w]) / p2[w])) break;
                    for(int v = w + 1; v < p2.size(); v++){
                        if(p2[i] * p2[j] > (((X / p2[k]) / p2[w]) / p2[v])) break;
                        ll ps =(((X / p2[k]) / p2[w]) / p2[v]);
                        ps /= p2[i];
                        ps /= p2[j];
                        //3 is allowed, but only once. 
                        //any from fr is allowed.
                        //any p2 in the current prod can be repeated.
                        vector<int> auxs2(ps+1, 0);
                        iota(auxs2.begin(), auxs2.end(), 0);
                        for(auto x : fr){
                            if(x > ps) break;
                            for(int j = x; j <= ps; j += x){
                                while(auxs2[j] % x == 0) auxs2[j] /= x;
                            }
                        }
                        vector<ll> v2 = {p2[i], p2[j], p2[v], p2[w], p2[k]};
                        for(auto x : v2){
                            for(int j = x; j <= ps; j += x){
                                while(auxs2[j] % x == 0) auxs2[j] /= x;
                            }
                        }
                        for(int j = 3; j <= ps; j += 3){
                            if(auxs2[j] % 3 == 0) auxs2[j] /= 3;
                        }
                        for(int u = 1; u <= ps; u++){
                            if(auxs2[u] == 1) ans += p2[i] * p2[j] * p2[k] * p2[w] * p2[v] * u;
                        }

                    }
                }
            }
        }
    }
    //#case 3
    fr.push_back(3);
    sort(fr.begin(), fr.end());
    for(int i = 0; i < p2.size(); i++){
        if(p2[i] * p2[i] > (((X / p2[i]) / p2[i]) / 9)) break;
        for(int j = i + 1; j < p2.size(); j++){
            if(p2[i] * p2[j] > (((X / p2[j]) / p2[j]) / 9)) break;
            for(int k = j + 1; k < p2.size(); k++){
                if(p2[i] * p2[j] > (((X / p2[k]) / p2[k]) / 9)) break;
                for(int w = k + 1; w < p2.size(); w++){
                    if(p2[i] * p2[j] > (((X / p2[k]) / p2[w]) / 9)) break;
                    ll ps =(((X / p2[k]) / p2[w]) / 9);
                    ps /= p2[i];
                    ps /= p2[j];
                    //3 is allowed now.
                    vector<int> auxs2(ps+1, 0);
                    iota(auxs2.begin(), auxs2.end(), 0);
                    for(auto x : fr){
                        if(x > ps) break;
                        for(int j = x; j <= ps; j += x){
                            while(auxs2[j] % x == 0) auxs2[j] /= x;
                        }
                    }
                    vector<ll> v2 = {p2[i], p2[j], p2[w], p2[k]};
                    for(auto x : v2){
                        for(int j = x; j <= ps; j += x){
                            while(auxs2[j] % x == 0) auxs2[j] /= x;
                        }
                    }
                    for(int u = 1; u <= ps; u++){
                        if(auxs2[u] == 1) ans += p2[i] * p2[j] * p2[k] * p2[w] * 9 * u;
                    }
                }
            }
        }
    }

    cout << ans << "\n";
}

//3631302350102895406 = WA
//8580561004105282089 = WA  