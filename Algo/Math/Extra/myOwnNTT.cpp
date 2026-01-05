//Not impressive
//Not new
//But my own code 
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


void DFT(vector<Mint> &vec, int s){
    int n = vec.size();
    int hf = n / 2;
    Mint w = 31;
    for(int i = n; i < (1 << 23); i <<= 1) w = w*w;
    if(s == 1){
        vector<Mint> nvec(vec.size());
        int pl = 1;
        for(int bt = hf; bt >= 1; bt >>= 1){
            int jmp = bt;
            int cur = 0;
            for(int bs = 0; bs < n; bs += bt * 2){
                for(int j = 0; j < bt; j++){
                    nvec[bs + j] = vec[bs + 2*j];
                    nvec[bs + j + jmp] = vec[bs + 2*j + 1];
                }
            }
            vec = nvec;
        }
    }
    
    for(int st = (s == 1 ? 1 : n/2); (s == 1 && st < n) || (s == -1 && st >= 1); st = (s == 1 ? st << 1 : st >> 1)){
        Mint pw = w.pow(n + s*(hf/st));
        for(int j = 0; j < n; j += 2*st){
            Mint cw = 1;
            for(int k = j; k < j + st; k++){
                Mint aux1 = vec[k];
                Mint aux2 = vec[k + st];
                if(s == 1){
                    vec[k] = aux1 + aux2 * cw;
                    vec[k + st] = aux1 - aux2 * cw;
                }else{
                    vec[k] = aux1 + aux2;
                    vec[k + st] = (aux1 - aux2) * cw;
                }
                cw *= pw;
            }
        }
    }
    if(s == -1){
        vector<Mint> nvec(vec.size());
        int pl = 1;
        for(int bt = 1; bt <= hf; bt <<= 1){
            int cur = 0;
            for(int bs = 0; bs < n; bs += bt * 2){
                for(int j = 0; j < bt; j++){
                    nvec[bs + 2*j] = vec[bs + j];
                    nvec[bs + 2*j + 1] = vec[bs + j + bt];
                }
            }
            vec = nvec;
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int pt = 1;
    while(pt < n+m-1) pt *= 2;
    vector<Mint> a(pt), b(pt);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a[i] = x;
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        b[i] = x;
    }
    DFT(a, 1);
    DFT(b, 1);
    for(int j=0;j<pt;j++) a[j] *= b[j];
    DFT(a, -1);
    for(auto &x : a) x /= pt;
    for(int j=0;j<n+m-1;j++) cout << a[j] << " ";
    cout << "\n";
}
