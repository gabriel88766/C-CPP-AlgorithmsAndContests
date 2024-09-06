#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

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
    Mint operator/= (Mint u){ //division untested, MOD not prime, u.v must be coprime with MOD.
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

int z[2000005]; //Lenght of greatest prefix(sz) equals substr (i, i+sz-1) 
//Z-function
void zfunc(string s){
    int lm = 0, rm = 0;
    for(int i=0;i<s.size();i++) z[i] = 0;
    for(int i=1;i<s.size();i++){
        if(i < rm){
            z[i] = min(z[i-lm], rm-i);
        }
        while(i+z[i] < s.size() && s[i+z[i]] == s[z[i]]) z[i]++;
        if(i + z[i] > rm){
            rm = i + z[i];
            lm = i;
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string a, l, r;
    cin >> a >> l >> r;
    //first for each i, find max j, a[j] ... a[i] < l
    //then for each i, find min j, a[j] ... a[i] <= r
    //how to? prefix kmp, compare same len..
    string s = l + "#" + a;
    zfunc(s);
    vector<int> vl(a.size()+1, 0), vr(a.size()+1, -1);
    int sz = l.size();
    for(int i=2*l.size();i<=l.size()+a.size(); i++){
        int k = i - l.size() + 1; 
        int j = k - l.size() - 1; //starts in 0
        if(z[k] == sz){
            vr[k-1] = j;
        }else{
            if(l[z[k]] < a[j+z[k]]) vr[k-1] = j;
            else{
                vr[k-1] = j-1; //first non zero lower than or equal to j-1
            }
        }
    }
    s = r + "#" + a;
    zfunc(s);
    sz = r.size();
    for(int i=r.size()+a.size(); i>=2*r.size(); i--){
        int k = i - r.size() + 1; 
        int j = k - r.size() - 1; //starts in 0
        if(z[k] == sz){
            vl[k-1] = j;
        }else{
            if(r[z[k]] < a[j+z[k]]){ // r=38389 a[..] = 38766
                vl[k-1] = j+1;
            } else{ // r=38389 a[..] = 38269
                vl[k-1] = j;
            }
        }
    }
    int n = a.size();
    vector<Mint> ps(n+1, 0);
    ps[0] = 1;
    a = " " + a;
    for(int i=1;i<=n;i++){
        ps[i] = ps[i-1];
        if(a[i-1] == '0'){
            //  st.update(i-2, 0);
            Mint val = ps[i-2];
            if(i > 2) val -= ps[i-3];
            ps[i-2] -= val;
            ps[i-1] -= val;
            ps[i] -= val; 
        }
        if(vl[i] <= vr[i]){
            ps[i] += ps[vr[i]];
            if(vl[i]) ps[i] -= ps[vl[i]-1];
            // st.update(i, st.query(vl[i], vr[i]));
        }
    }
    cout << ps[n] - ps[n-1] << "\n";

}
