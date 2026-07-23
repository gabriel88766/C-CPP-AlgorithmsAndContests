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

const int N = 4e5+2; //O(N) preprocessing, O(1) query

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
    //ans = 1/2^N * (|N-X| * (N, 0) + |N-X-2| * (N, 1) + ... ); 
    init();
    int t;
    cin >> t;
    vector<Mint> ans(t), fact(t);
    vector<int> N(t), X(t);
    vector<tuple<int, int, int, int>> qr;
    for(int i=0;i<t;i++){
        cin >> N[i] >> X[i];
        int u = (N[i] - X[i]);
        //if u <= 0 then sum(2*i + X - N) * (N, i), because X is too large
        //if u >= 2*N then sum(N-X-2*i) * (N, i), because X is too negative
        //else in for i <= u/2 sum(N-X-2*i) * (N, i) for i > u/2 sum(X-N+2*i) * (N, i);
        if(u <= 0){
            ans[i] += (X[i] - N[i]) * Mint(2).pow(N[i]);
            ans[i] += 2 * N[i] * Mint(2).pow(N[i]-1);
        }else if(u >= 2*N[i]){
            ans[i] += (N[i] - X[i]) * Mint(2).pow(N[i]);
            ans[i] -= 2 * N[i] * Mint(2).pow(N[i]-1);
        }else{
            u/=2;
            ans[i] += Mint(2).pow(N[i]) * (X[i] - N[i]);
            ans[i] += N[i] * Mint(2).pow(N[i]);
            qr.push_back({N[i], u, i, 2*(N[i] - X[i])});
            if(u != 0) qr.push_back({N[i] - 1, u - 1, i, -4 * N[i]});
        }
        fact[i] = 1/Mint(2).pow(N[i]);
    }
    sort(qr.begin(), qr.end());
    int bg = 0;
    vector<Mint> cc(200005);
    cc[0] = 1;
    for(auto [n, u, j, mtp] : qr){
        // ans[j] += mtp * Sn(n, u)...
        bool chg = false;
        while(n >= bg + 400){
            chg = true;
            bg += 400;
        }
        if(chg){
            for(int i=1;i<=bg;i++){
                cc[i] = cc[i-1] + nCr(bg, i);
            }
        }
        Mint cur;
        int bgl;
        if(u >= bg){
            bgl = u;
            cur = Mint(2).pow(u); //Sn(u, u);
        }else{
            bgl = bg;
            cur = cc[u];
        }
        //Sn(n, u) = Sn(n-1, u-1) + Sn(n-1, u) = 2*Sn(n-1, u) - nCr(n-1, u);
        for(int j=bgl+1;j<=n;j++){
            cur = 2*cur - nCr(j-1, u);
        }
        ans[j] += Mint(mtp) * cur;
    }
    for(int i=0;i<t;i++) cout << ans[i]*fact[i] << "\n";
    // Naive solution
    // while(t--){
    //     int N, X;
    //     cin >> N >> X;
    //     Mint aux = Mint(1) / Mint(2).pow(N);
    //     Mint ans = 0;
    //     for(int i=0;i<=N;i++){
    //         ans += abs(N - 2*i - X) * nCr(N, i);
    //     }
    //     ans *= aux;
    //     cout << ans << "\n";
    // }
}
