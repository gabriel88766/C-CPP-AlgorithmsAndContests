#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 31700;
int p[N]; // 0 if prime, 1 if not prime
vector<ll> pr;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            pr.push_back(i);
        }
    }
}


ll binmul(__int128 a, __int128  b, ll  m){
    return (a * b) % m;
}


ll binpow(ll a, ll  b, ll  m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = binmul(ans, a, m);
        a = binmul(a, a, m);
        b >>= 1;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1){
            cout << "2 1\n";
            continue;
        }
        int an = n;
        ll m = 1;
        set<int> f;
        set<int> of;
        for(auto &x : pr){
            if(an % x) continue;
            f.insert(x);
            while(!(an % x)){
                an /= x;
                m *= x;
            }
            m *= x;
            if(x == 2) m *= x;
        }
        if(an != 1){
            f.insert(an);
            m *= an;
            m *= an;
        }
        if(m > 1e18) m /= 2;
        ll mf = m;
        for(auto &x : f){
            mf /= x;
            mf *= (x-1);
        }
        for(auto &x : f){
            int cur = x - 1;
            for(auto &y : pr){
                if(y*y > cur) break;
                if(!(cur % y)){
                    while(!(cur % y)) cur /= y;
                    if((!f.count(y)) && (!of.count(y))) of.insert(y);
                }
            }
            if(cur != 1){
                if((!f.count(cur)) && (!of.count(cur))) of.insert(cur);
            }
        }
        for(int i=2;i<=m;i++){
            if(gcd(i, m) == 1){
                mf = m;
                for(auto &x : f){
                    mf /= x;
                    mf *= (x-1);
                }
                for(auto &x : f){
                    while(mf % x == 0 && binpow(i, mf/x, m) == 1) mf /= x;
                }
                for(auto &x : of){
                    while(mf % x == 0 && binpow(i, mf/x, m) == 1) mf /= x;
                }
                if(mf % n != 0) continue;
                ll a = binpow(i, mf/n, m);
                assert(a <= 1e18);
                assert(m <= 1e18);
                assert(binpow(a, n, m) == 1);
                cout << a << " " << m << "\n";
                break;
            }
        }
    }
}
