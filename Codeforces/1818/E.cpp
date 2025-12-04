#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;



const int N = 3e6+5; //O(N) preprocessing, O(1) query
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
Mint fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}
 
Mint sum[N];
//O(k log MOD)
Mint lagrange1(int d){
    // sum[0] = 0;
    // for(int i=1;i<=(k+2);i++){
    //     sum[i] = sum[i-1] + Mint(i).pow(k); //JUST AN EXAMPLE!!
    // } //as input from 0 to d;
  
    //https://en.wikipedia.org/wiki/Lagrange_polynomial
    // ym = sum[m], k+2 points and poly is dg k+1, you may need replace "k+2" by "k+1"
    Mint ans = 0;
    Mint sumx = 0;
    for(int i=0;i<=d;i++) sumx -= i;
    for(int i=0;i<=d;i++){ //PLEASE, FOR GOD SAKES, DON'T USE I = 0 HERE
        if((d-i) % 2) ans -= sum[i] * invfat[d-i] * invfat[i] * (sumx + i);
        else ans += sum[i] * invfat[d-i]* invfat[i] * (sumx + i);
    }
    return ans;
    
}

Mint lagrange2(int d){
    // sum[0] = 0;
    // for(int i=1;i<=(k+2);i++){
    //     sum[i] = sum[i-1] + Mint(i).pow(k); //JUST AN EXAMPLE!!
    // } //as input from 0 to d;
  
    //https://en.wikipedia.org/wiki/Lagrange_polynomial
    // ym = sum[m], k+2 points and poly is dg k+1, you may need replace "k+2" by "k+1"
    Mint ans = 0;
    for(int i=0;i<=d;i++){ //PLEASE, FOR GOD SAKES, DON'T USE I = 0 HERE
        if((d-i) % 2) ans -= sum[i] * invfat[d-i] * invfat[i];
        else ans += sum[i] * invfat[d-i]* invfat[i];
    }
    return ans;
    
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int d;
    cin >> d;
    for(int i=0;i<=d;i++) cin >> sum[i].v;
    Mint i1 = lagrange1(d);
    Mint i2 = lagrange2(d);
    for(int i=0;i<=d;i++) cin >> sum[i].v;
    Mint i3 = lagrange1(d);
    //i3 = i1 + i2 * s * d;

    cout << (i3 - i1) / (d * i2) << "\n";
}
