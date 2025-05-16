#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
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

const int N = 5000;
int cnt[N+1];
vector<int> lp(N+1);
vector<int> pr;
void sieve(){
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}

ull basis[N+1][6];
ull ins_b[N+1][6];
int get_order(ull *curb){
    for(int j=5;j>=0;j--){
        if(curb[j] != 0) return 63 - __builtin_clzll(curb[j]) + 64*j;
    }
    return -1; //no order
}
bool xorify(ull *curb){
    int ord = get_order(curb);
    if(ord == -1) return false;
    bool isb = false;
    for(int j=5;j>=0;j--) if(ins_b[ord][j]) isb = true;
    if(!isb){
        for(int j=5;j>=0;j--) ins_b[ord][j] = curb[j];
        return false;
    }else{
        for(int j=5;j>=0;j--) curb[j] ^= ins_b[ord][j];
        return true;
    }
}
ull cur[6];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    vector<int> sp;
    for(int i=2;i<=2500;i++){
        if(lp[i] == i) sp.push_back(i);
    }
    for(int i=1;i<=5000;i++){
        for(int j=0;j<sp.size();j++){
            int c1 = j / 64;
            int c2 = j % 64;
            int cnt = 0;
            int num = i;
            while(num % sp[j] == 0){
                num /= sp[j];
                cnt++;
            }
            if(cnt % 2) basis[i][c1] |= 1ULL << c2;
        }
    }
    int n;
    cin >> n;
    int xp = n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(x > 2500 && lp[x] == x){
            if(!cnt[x]){
                xp--;
                cnt[x] = 1;
            } 
        }else{
            for(int j=0;j<6;j++) cur[j] = basis[x][j];
            while(xorify(cur));
            if(get_order(cur) != -1) xp--;
        }
    }
    cout << Mint(2).pow(xp) << "\n";
}
