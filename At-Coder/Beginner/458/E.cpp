#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(ll u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
        if(u < 0) return (Mint(1)/v).pow(-u);
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
    Mint& operator*= (const Mint &u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint& operator+= (const Mint &u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint& operator-= (const Mint &u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint& operator/= (const Mint &u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (const Mint &u) const { return v == u.v;}
    bool operator!= (const Mint &u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 3e6+2; //O(N) preprocessing, O(1) query

//Using Mint
Mint fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}
Mint nCr(ll a, ll b){
    assert(a >= b); //catch silly bugs
    return fat[a]*invfat[a-b]*invfat[b];
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    ll a, b, c;
    cin >> a >> b >> c;
    Mint ans = 0;
    for(int i=1;i<=b;i++){
        //quantity of changes from 1 to 3 or 3 to 1.
        int q1 = 1 + i/2, q3 = (i + 1)/2;
        auto calc = [&](){
            if(q1 <= a && q3 <= c){
                //count integer sol of
                //a1 + a2 + a3 + ... + aq1 = a - q1;
                //c1 + c2 + c3 + ... + cq3 = c - q3;
                //put i '2' fixed 
                //remaining ??? a1 + a2 + a3 + ... + a(a+c) + a(a+c+1) = b - i;
                //nCr(a-1, q1-1) * nCr(c-1, q3-1) * nCr(a+b+c-i, a + c);
                ans += nCr(a - 1, q1-1) * nCr(c - 1, q3 - 1) * nCr(a + b + c - i, a + c);
            }
        };
        //first count 1 3 1 3 1 ...
        calc();
        //then 3 1 3 1 ...
        swap(q1, q3);
        calc();
    }
    cout << ans << "\n";
}
