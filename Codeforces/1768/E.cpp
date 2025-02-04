#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll MOD;

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

const int N = 3e6+5; //O(N) preprocessing, O(1) query

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

int msort(vector<int> &v, int n){
    auto srt = v;
    sort(srt.begin(), srt.end());
    if(v == srt) return 0;
    auto v1 = v;
    sort(v1.begin(), v1.begin() + 2*n);
    if(v1 == srt) return 1;
    v1 = v;
    sort(v1.begin() + n, v1.begin() + 3*n);
    if(v1 == srt) return 1;
    v1 = v;
    sort(v1.begin(), v1.begin() + 2*n);
    sort(v1.begin() + n, v1.begin() + 3*n);
    if(v1 == srt) return 2;
    v1 = v;
    sort(v1.begin() + n, v1.begin() + 3*n);
    sort(v1.begin(), v1.begin() + 2*n);
    if(v1 == srt) return 2;
    return 3;
}
Mint tt[4], tt2[4];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("out", "w", stdout); //test input
    int n;
    cin >> n >> MOD;
    init();
    tt[0] = 1; //1 2 3
    tt[1] = 2*(fat[2*n] - tt[0]) - (fat[n] - 1);//2 1 3 and 1 3 2
    tt[3] = (fat[3*n] - 2 *(nCr(2*n, n) * fat[n] * fat[2*n]));//33  xxx  11  (all - 1 1 x - x 3 3 + 1 13 3)
    for(int i=0;i<=n;i++){
        //quantity of 1's in mid
        tt[3] += nCr(n, i) * nCr(n, n-i) * fat[n] * nCr(2*n - i, n) * fat[n] * fat[n];
    }
    tt[2] = fat[3*n] - tt[3] - tt[1] - tt[0];
    // cout << tt[0] << " " << tt[1] << " " << tt[2] << " " << tt[3] << "\n";
    cout << tt[1] + 2*tt[2] + 3*tt[3] << "\n";
}
