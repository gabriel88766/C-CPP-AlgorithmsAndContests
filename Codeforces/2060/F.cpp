#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    ll v;
    //static const int MOD = MOD_val;
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
    ll gcd_euclid(ll a, ll b, ll &x, ll &y){ //solves ax+by = g where g = gcd(a,b)
        if(b == 0){ //meaning 1 * a - 0 * 0 = a, (gcd)
            x = 1; y = 0;
            return a;
        }
        ll d = gcd_euclid(b, a % b, y, x); //if b > a then this step reverses it
        y -= x * (a/b); 
        return d;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    /*Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}*/
    Mint operator/= (Mint u){ //division , MOD not prime, u.v must be coprime with MOD.
        ll x, y;
        ll g = gcd_euclid(u.v, MOD, x, y);
        assert(g == 1);
        (*this) *= x; 
        return *this;
    }
    bool operator== (const Mint u) const { return v == u.v;}
    bool operator!= (const Mint u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 2e5+1;
vector<int> ad[N];
vector<int> fct[N];
int pr[N];
Mint fat[N], invfat[N];
void init(){
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            ad[j].push_back(i);
        }
    }
    for(int i=2;i<N;i++){
        if(!pr[i]){
            for(int j=i;j<N;j+=i){
                pr[j] = 1;
                int aux = j, cnt = 0;
                while(!(aux % i)){
                    aux /= i;
                    cnt++;
                }
                fct[j].push_back(cnt);
            }
        }
    }
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}

Mint nCr(ll a, ll b){
    Mint ans = 1;
    for(int i=0;i<b;i++) ans *= (a - i);
    ans *= invfat[b];
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        int k, n;
        cin >> k >> n;
        if(n == 1){
            for(int i=1;i<=k;i++) cout << 1 << " ";
            cout << "\n";
            continue;
        }
        vector<Mint> ans(k+1, 0);
        ans[1] = n;
        cout << n << " ";
        for(int i=2;i<=k;i++){
            Mint c1 = 1;
            for(auto x : fct[2*i]){
                c1 *= nCr(n + x, x);
            }
            c1 -= 1;
            for(auto x : ad[2*i]){
                if(x == i) continue;
                if(x == 2*i) continue;
                c1 -= ans[x];
            }
            ans[i] = c1;
            cout << ans[i] << " ";
        }

        cout << "\n";
    }
}
