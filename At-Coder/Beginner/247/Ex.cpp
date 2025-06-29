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

// if MOD 786433, w = 5 and change to 1 << 18
void ntt(vector<Mint> &a, int n, int s) { //31^(2^23) == 1 (mod 998244353), so, for example, if n = 2^16, w1 = 31^(2^7)
    Mint w1 = 31;
    for(int i = n; i < (1 << 23); i <<= 1) w1 *= w1;
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

vector<Mint> multiply(vector<Mint> a, vector<Mint> b) {
    int n = 1;
    while(n < a.size() + b.size() - 1) n *= 2;
    a.resize(n);
    b.resize(n);
    ntt(a,n,1);
    ntt(b,n,1);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    ntt(a,n,-1);
    for (int i = 0; i < n; i++) a[i] /= n;
    while(a.back() == 0) a.pop_back();
    return a;
}

vector<Mint> mtp(int l, int r){
    if(l == r){
        vector<Mint> ans(2);
        ans[0] = 1;
        ans[1] = l;
        if(l == 0) ans.pop_back();    
        return ans;
    }
    int m = (l+r)/2;
    return multiply(mtp(l, m), mtp(m+1, r));
}


struct Cmp{
    bool operator()(const vector<Mint> &u, const vector<Mint> &v) const{
        return u.size() < v.size();
    }
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("out", "w", stdout); //test input
    // int n = 6;
    // auto ans = mtp(0, n-1);
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    //now this multiply is also tricky...
    multiset<vector<Mint>, Cmp> pq; //it was a priority queue but I failed.
    for(int i=1;i<=n;i++){
        if(cnt[i]){
            auto cv = mtp(0, cnt[i] - 1);
            pq.insert(cv);
        }
    }
    while(pq.size() >= 2){
        auto u = *pq.begin();
        pq.erase(pq.begin());
        auto v = *pq.begin();
        pq.erase(pq.begin());
        auto cv = multiply(u, v);
        pq.insert(cv);
    }
    auto ans = *pq.begin();
    Mint rans = 0;
    for(int i=k%2;i<=min(k, (int)ans.size()-1); i += 2) rans += ans[i];
    cout << rans << "\n";
}
