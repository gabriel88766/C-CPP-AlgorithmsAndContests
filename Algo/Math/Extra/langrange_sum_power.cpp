#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

//calculate Sum 1^x + 2^x + .... + k^x for k < MOD and x <= 1'000'000
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
 
Mint sum[N];
//O(k log MOD)
Mint sumpow(ll n, ll k){
    sum[0] = 0;
    for(int i=1;i<=(k+2);i++){
        sum[i] = sum[i-1] + Mint(i).pow(k); //JUST AN EXAMPLE!!
    }
    if(n <= (k+1)) return sum[n];
    else{
        //https://en.wikipedia.org/wiki/Lagrange_polynomial
        // ym = sum[m], k+2 points and poly is dg k+1, you may need replace "k+2" by "k+1"
        Mint ans = 0;
        Mint prod = 1;
        for(int i=1;i<=(k+2);i++) prod *= (n - i);
        for(int i=1;i<=(k+2);i++){ //PLEASE, FOR GOD SAKES, DON'T USE I = 0 HERE
            if(((k+2)-i) % 2) ans -= sum[i] * prod / (fat[(k+2)-i]*fat[i-1] * (n - i));
            else ans += sum[i] * prod / (fat[(k+2)-i]*fat[i-1] * (n - i));
        }
        return ans;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    ll n, k;
    cin >> n >> k;
    cout << sumpow(n, k) << "\n";
}
