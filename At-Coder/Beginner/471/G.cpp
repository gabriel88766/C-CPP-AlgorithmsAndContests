#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    int v;
    //static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(int u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
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
    Mint operator*= (Mint u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (const Mint u) const { return v == u.v;}
    bool operator!= (const Mint u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

// if MOD 786433, w = 5 and change to 1 << 18
void ntt(vector<Mint> &a, int n, int s){
    Mint w = s == 1 ? 31 : 128805723;
    for(int i = n; i < (1 << 23); i <<= 1) w *= w;
    int hf = n/2;
    vector<Mint> aux(a.size());
    for(int j = 2; j <= n; j *= 2){
        Mint cw = w.pow(n/j);
        int jmp = n/j;
        aux.swap(a);
        Mint wx = 1;
        for(int k = 0; k < j/2; k++){
            for(int i = 0; i < jmp; i++){ 
                Mint t1 = aux[i + 2 * k * jmp];
                Mint t2 = aux[i + (2 * k + 1) * jmp];
                a[i + k * jmp] = t1 + wx * t2;
                a[i + k * jmp + hf] = t1 - wx * t2;
            }
            wx = wx * cw;
        }
    }
}

vector<Mint> mult(vector<Mint> a, vector<Mint> b) {
    int n = 1;
    while(n < a.size() + b.size() - 1) n *= 2;
    a.resize(n);
    b.resize(n);
    ntt(a,n,1);
    ntt(b,n,1);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    ntt(a,n,-1);
    Mint inv  = Mint(1)/n;
    for (int i = 0; i < n; i++) a[i] *= inv;
    while(a.size() > 1 && a.back() == 0) a.pop_back();
    return a;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ull n, k, seed, m;
    cin >> n >> k >> seed >> m; 
    vector<int> str(n + 1);
    ull state = seed;
    for(int i = 1; i <= n; i++){
        if(i <= m){
            cin >> str[i];
        }else{
            ull x = (((state >> 18) ^ state) >> 27) & 0xFFFFFFFF;
            ull r = state >> 59;
            ull y = ((x >> r) + (x << (32 - r))) & 0xFFFFFFFF;
            str[i] = y % k;
            state = state * 6364136223846793005ULL + 2026081520260815ULL;
        }
    }
    vector<bool> vw(k);
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        if(x == 0) vw[i] = false;
        else vw[i] = true;
    }
    vector<int> ans(k);
    //first letter
    for(int i=0;i<k;i++){
        int cl = str[1] + i;
        cl %= k;
        if(vw[cl]) ans[i]++;
    }
    
    //letter = z, dl = u, tt = (z+u)%k; let the gap vec, ans += pf[tt]
    vector<vector<Mint>> pf(k, vector<Mint>(2 * k));
    for(int i=0; i< k; i++){ //gap = i;
        //A = 0, B = i. find the profile 
        for(int j = 0; j < k; j++){
            int u = j;
            int v = (i + j) % k;
            if(vw[u] == false && vw[v] == true){ // 0 -> j with gap i.
                pf[i][k-j-1] += 1;
            }
        }
        for(int j = k; j < 2 * k; j++){
            pf[i][j] = pf[i][j-k];
        }
    }
    vector<vector<Mint>> qt(k, vector<Mint>(k));
    for(int i=1;i<n;i++){
        int gap = str[i+1] - str[i];
        if(gap < 0) gap += k;
        int u = str[i];
        //pf[gap][u], pf[gap][u+1], ... {0, 0, 1, 3, 0, 2, 9, 2, 3} (this is pf[gap] vec for 0) {0, 1, 0, 1, 1, 1, 0, 1} (this is the sum of each i)
        //if convolution -> we get the values for each in 8192 * 8192 * log(8192) (too bad...)
        qt[gap][u]+=1;
    }
    for(int i = 0; i < k; i++){
        //conv(qt[i], pf[i]);
        auto cans = mult(qt[i], pf[i]);
        for(int j = k-1; j < 2*k - 1; j++){
            if(cans.size() <= j) break;
            if(j == k-1) ans[0] += cans[j].v;
            else ans[k - (j - (k-1))] += cans[j].v;
        }
    }
    for(int i=0;i<k;i++){
        cout << ans[i] << "\n";
    }

    
}
