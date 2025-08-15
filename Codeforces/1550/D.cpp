#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(int u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
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


const int N = 2e5+3; //O(N) preprocessing, O(1) query

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
    if(b < 0 || b > a || a < 0) return 0;
    return fat[a]*invfat[a-b]*invfat[b];
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("i    n", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        int mn = min(r, n - l);
        Mint ans = 0;
        int i1 = -1, i2 = -1;
        for(int i=mn;i>=1;i--){
            if(i + n <= r && 1 - i >= l){
                assert(i1 + 1 >= n && i2 + 1 >= n);
                if(n % 2) ans += Mint(i) * nCr(n, n/2) * 2;
                else ans += Mint(i) * nCr(n, n/2);
                break;
            }else{
                if(i1 == -1 && i2 == -1){
                    i1 = 0, i2 = 0;
                    for(int j=1;j<=n;j++){
                        if(j - i >= l) i1++;
                        if(j + i <= r) i2++;
                    }
                }else{
                    i1 = min(i1 + 1, n);
                    i2 = min(i2 + 1, n);
                }
                if(i1 + i2 < n) continue;
                int ins = i1 + i2 - n;
                // cout << i << " " << i1 << " " << i2 << " " << ins << " ";
                int sl1 = i1 - ins;
                int sl2 = i2 - ins;
                if(n % 2){
                    ans += nCr(ins, n/2 - sl1);
                    ans += nCr(ins, n/2 + 1 - sl1);
                }else{
                    ans += nCr(ins, n/2 - sl1);
                }
            }
            // cout << ans << "\n";
        }
        cout << ans << "\n";
    }
}
