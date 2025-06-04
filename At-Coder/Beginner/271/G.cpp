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

vector<vector<Mint>> multMatrix(vector<vector<Mint>> a, vector<vector<Mint>> b){
    int size = a.size();
    vector<vector<Mint>> ans(size, vector<Mint>(size));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            Mint cel = 0;
            for(int k=0;k<size;k++){
                cel = (cel + a[i][k] * b[k][j]);
            }
            ans[i][j] = cel;
        }
    }
    return ans;
}

vector<vector<Mint>> binpow(vector<vector<Mint>> a, ll b){
    int size = a.size();
    vector<vector<Mint>> ans(size, vector<Mint>(size)); //idt
    for(int i=0;i<size;i++) ans[i][i] = 1; //idt

    while(b > 0){
        if(b & 1) 
            ans = multMatrix(ans, a);
        a = multMatrix(a, a);
        b >>= 1;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    Mint p1 = Mint(x) / 100; //takahashi
    Mint p2 = Mint(y) / 100; //aoki
    vector<vector<Mint>> mat(24, vector<Mint>(24));
    Mint p = 1;
    for(auto &c : s){
        if(c == 'T') p *= (1 - p1);
        else p *= (1-p2);
    }
    for(int i=0;i<24;i++){
        for(int j=0;j<24;j++){
            //probability that j is next after i
            Mint px = 1;
            if(j > i){
                for(int k=i+1;k<j;k++){
                    if(s[k] == 'T') px *= (1 - p1);
                    else px *= (1 - p2);
                }
                if(s[j] == 'T') px *= p1;
                else px *= p2;
                mat[i][j] = px / (1 - p);
            }else{
                //i > j
                for(int k=i+1;k<24;k++){
                    if(s[k] == 'T') px *= (1 - p1);
                    else px *= (1 - p2);
                }
                for(int k=0;k<j;k++){
                    if(s[k] == 'T') px *= (1 - p1);
                    else px *= (1 - p2);
                }
                if(s[j] == 'T') px *= p1;
                else px *= p2;
                mat[i][j] = px / (1 - p);
            }
        }
    }
    mat = binpow(mat, n);
    Mint ans = 0;
    for(int i=0;i<24;i++){
        if(s[i] == 'A') ans += mat[23][i];
    }
    cout << ans << "\n";
}
