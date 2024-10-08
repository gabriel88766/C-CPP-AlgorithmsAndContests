#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+5; //O(N) preprocessing, O(1) query
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
Mint fat[N];
void init(){ //MOD must be prime
    fat[0] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
}

ll n, k;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    cin >> n >> k;
    vector<Mint> sum(k+3);
    sum[0] = 0;
    for(int i=1;i<=k+2;i++){
        sum[i] = sum[i-1] + Mint(i).pow(k);
    }
    if(n <= k+2) cout << sum[n];
    else{
        //https://en.wikipedia.org/wiki/Lagrange_polynomial
        // ym = sum[m], k+1 points
        Mint ans = 0;
        Mint prod = 1;
        for(int i=1;i<=k+2;i++) prod *= (n - i);
        for(int i=1;i<=k+2;i++){
            if((k+2-i) % 2) ans -= sum[i] * prod / (fat[k+2-i]*fat[i-1] * (n - i));
            else ans += sum[i] * prod / (fat[k+2-i]*fat[i-1] * (n - i));
        }
        cout << ans << "\n";
    }
}
