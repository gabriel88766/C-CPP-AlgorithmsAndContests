#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    ll v;
    Mint(){ v = 0;}
    Mint(ll u){ v = (u >= 0 ? u % MOD : u % MOD + MOD);}
    Mint pow(ll u){
        Mint ans = 1;
        Mint aux = *this;
        while(u){
            if(u & 1) ans *= aux;
            aux *= aux;
            u >>= 1;
        }
        return ans;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (Mint u){ return v == u.v;}
    bool operator!= (Mint u){ return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 1e6+5;
int p[N]; // 0 if prime, 1 if not prime
int cnt[N];
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
        }
    }
}

ll num[N];
void weirdsieve(ll l, ll r){
    for(ll i=l;i<=r;i++) num[i-l] = i;
    for(ll i=2;i<N;i++){
        if(!p[i]){
            for(ll j=((l+i-1)/i)*i; j<= r; j += i){
                while(!(num[j-l] % i)){
                    cnt[i]++;
                    num[j-l] /= i;
                }
            }
        }
    }
}

void acc(ll k){
    for(ll i = 2; i < N && i <= k; i++){
        if(!p[i]){
            for(ll j=i;j<=k;j+=i){
                ll aux = j;
                while(!(aux % i)){
                    cnt[i]--;
                    aux /= i;
                }
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    ll n, k;
    cin >> n >> k;
    weirdsieve(n-k+1, n);
    acc(k);
    Mint ans = 1;
    for(int i=2;i<N;i++){
        if(cnt[i]) ans *= (cnt[i] + 1);
    }
    for(int i=0;i<N;i++){
        if(num[i] != 0 && num[i] != 1) ans *= 2;
    }
    cout << ans << "\n";
}
