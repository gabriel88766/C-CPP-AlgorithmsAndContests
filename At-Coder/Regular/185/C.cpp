#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const ull MOD = 9223372037190320129ULL;
struct Mint{
    ull v;
    Mint(){ v = 0;}
    Mint(ull u){ v = u % MOD;}

    Mint pow(ull u){
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
    Mint operator*= (Mint u){ v = ((__int128)u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v >= MOD-u.v ? v-(MOD-u.v) : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v < u.v ? v+(MOD-u.v) : v-u.v); return *this;}
    Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (Mint u){ return v == u.v;}
    bool operator!= (Mint u){ return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

// if MOD 786433, w = 5 and change to 1 << 18
void ntt(vector<Mint> &a, int n, int s) { //1927755973360576764^(2^26) == 1 (mod 9223372037190320129), so, for example, if n = 2^16, w1 = 1927755973360576764^(2^10)
    Mint w1 = 1927755973360576764ULL;
    for(int i = n; i < (1 << 26); i <<= 1) w1 *= w1;
    for (int i=0, j=0; i<n; i++) {
        if (i>j) swap(a[i], a[j]);
        for (int l=n/2; (j^=l) < l; l>>=1);
    }
    //w1^n = 1
    for(int i = 1; (1<<i) <= n; i++){
        int M = 1 << i;
        int K = M >> 1;
        Mint wn = w1.pow( n + s*(n/M)); 
        for(int j = 0; j < n; j += M) {
            Mint w = 1;
            for(int l = j; l < K + j; ++l){
                Mint t = w*a[l + K];
                a[l + K] = a[l] - t;
                a[l] = a[l] + t;
                w *= wn;
            }
        }
    }
}


//dont need modulus, just a big enough to hold long long:
void multiply(vector<Mint> &a, vector<Mint> b, int n) {
    ntt(a,n,1);
    ntt(b,n,1);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    ntt(a,n,-1);
    Mint inv  = Mint(1)/n;
    for (int i = 0; i < n; i++) a[i] *= inv;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, x;
    cin >> n >> x;
    vector<ll> cnt(x+1);
    vector<ll> rv(x+1);
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        cnt[v[i]]++;
    }
    int m = 1;
    while(2*x + 1 > m) m *= 2;
    vector<Mint> a(m);
    for(int i=0;i<=x;i++) a[i] = cnt[i];
    auto b = a;
    multiply(a, b, m);
    for(int i=0;i<=x/2;i++){
        a[2*i] -= cnt[i];
    }
    for(int i=0;i<=x;i++){
        rv[i] = a[i].v;
        rv[i] >>= 1;
    }
    vector<int> ans;

    if(x % 3 == 0 && cnt[x/3] >= 3){
        ans = {x/3, x/3, x/3};
    }else{
        //there is at least one number unique.
        for(int i=1;i<=x;i++){
            //let i is unique
            if(cnt[i] == 0) continue;
            ll ttx = rv[x-i];
            if(x - 2*i > 0){
                if(3*i == x){
                    ttx -= (cnt[i] * (cnt[i-1]))/2;
                }else{
                    ttx -= (cnt[i] * cnt[x - 2*i]);
                }
            }
            if(ttx > 0){
                for(int j=1;j<=x;j++){
                    if(j != i && x - i - j != i){
                        if(j == x - i - j){
                            if(cnt[j] >= 2){
                                ans = {i, j, j};
                                break;
                            }
                        }else if(cnt[j] && cnt[x-i-j]){
                            ans = {i, j, x-i-j};
                            break;
                        }
                    }
                }
            }else assert(ttx == 0);
        }
    }


    if(ans.size()){
        multiset<int> ms;
        for(auto x : ans) ms.insert(x);
        for(int i=1;i<=n;i++){
            if(ms.count(v[i])){
                cout << i << " ";
                ms.erase(ms.find(v[i]));
            }
        }
    }else cout << "-1\n";
}
 