#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

namespace poly{
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
    //warning, 31 is a primitive root of 998244353
    //If modulo change, change w1.
    void ntt(vector<Mint> &a, int s) { 
        int n = a.size();
        Mint w1 = 31;
        for(int i = n; i < (1 << 23); i <<= 1) w1 *= w1;
        for (int i=0, j=0; i<n; i++) {
            if (i>j) swap(a[i], a[j]);
            for (int l=n/2; (j^=l) < l; l>>=1);
        }
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
        Mint inv  = Mint(1)/n;
        a.resize(n);
        b.resize(n);
        ntt(a,1);
        ntt(b,1);
        for (int i = 0; i < n; i++) a[i] *= b[i];
        ntt(a,-1);
        for (int i = 0; i < n; i++) a[i] *= inv;
        return a;
    }
    struct Poly{
        vector<Mint> vec;
        
        Poly(){}
        Poly(Mint x){vec.resize(1, x);}
        Poly(int size){vec.resize(size);}
        Poly(vector<Mint> &vec){this->vec = vec; normalize();}  
        Poly(const Poly &p){this->vec = p.vec;}
        void normalize(){
            while(vec.size() > 1 && vec.back().v == 0) vec.pop_back();
        }
        // void negate(){
        //     for(int j=0;j<vec.size();j++) vec[j] = -vec[j].v;
        // }
        Poly mod_xk(int k){
            int x = min((int)this->vec.size(), k);
            Poly ans(x);
            for(int j=0;j<x;j++) ans.vec[j] = vec[j];
            ans.normalize();
            return ans;
        }
        Poly deriv1(){
            Poly ans(*this);
            ans.vec.pop_back();
            for(int j=0;j<ans.vec.size();j++) ans.vec[j] = (j+1) * vec[j+1];
            normalize();
            return ans; 
        }
        //this can be preprocessed (modulo divisions) or is going to take O(n log M)
        Poly integr1(){
            Poly ans(*this);
            ans.vec.push_back(0);
            ans.vec[0] = 0;
            for(int j=1;j<ans.vec.size();j++) ans.vec[j] = vec[j-1] / j;
            normalize();
            return ans;
        }
        Poly& operator+= (const Poly &pl){
            vec.resize(max(vec.size(), pl.vec.size()));
            for(int j=0;j<pl.vec.size();j++) vec[j] += pl.vec[j];
            normalize();
            return *this;
        }
        Poly& operator-= (const Poly &pl){
            vec.resize(max(vec.size(), pl.vec.size()));
            for(int j=0;j<pl.vec.size();j++) vec[j] -= pl.vec[j];
            normalize();
            return *this;
        }
        Poly& operator*= (const Poly &pl){
            vec = multiply(vec, pl.vec);
            normalize();
            return *this;
        }
        Poly operator* (const Poly &t) const {return Poly(*this) *= t;}
        Poly operator+ (const Poly &t) const {return Poly(*this) += t;}
        Poly operator- (const Poly &t) const {return Poly(*this) -= t;}
        Poly inv(int n){
            Poly B;
            for(int i = 1; ; i <<= 1){
                if(i == 1) B.vec = {Mint(1)/vec[0].v};
                else{
                    //Bk = Bk-1 * (2 - ABk-1) mod(x^(2^k))
                    B  = (B * (Poly(Mint(2)) - (this->mod_xk(i) * B)).mod_xk(i)).mod_xk(i);
                }
                if(i >= n) break;
            }
            B.vec.resize(n);
            normalize();
            return B;
        }
        //Here, a0 = 1. If a0 != 1, then ans[0] = ln(a0) (which is not defined in Modulo)
        Poly log(int n){
            Poly p1 = this->inv(n);
            Poly p2 = this->deriv1();
            Poly ans = (p1*p2).mod_xk(n-1).integr1();
            return ans;
        }
        //Here a0 = 0, because e^(P(x) + a0) = e^P(x) * e^a0, again real numbers unless a0=0
        Poly exp(int n){
            Poly Q(Mint(1));
            //Qk = (Qk-1) * (1 + A - log(Qk-1)) 
            for(int i=2;;i <<= 1){
                Q = (Q * (Poly(Mint(1)) + this->mod_xk(i)  - Q.log(i))).mod_xk(i);
                if(i >= n) break;
            }
            Q.vec.resize(n);
            normalize();
            return Q;
        } 
    };
    
}

using namespace poly;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<Mint> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].v;
    }
    Poly po(a);
    Poly ans = po.exp(n);
    for(int j=0;j<n;j++){
        if(j < ans.vec.size()) cout << ans.vec[j] << " ";
        else cout << "0 ";
    }
    cout << "\n";
}
