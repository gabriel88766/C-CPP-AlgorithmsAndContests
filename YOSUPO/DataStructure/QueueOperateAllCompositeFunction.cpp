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

pair<Mint, Mint> getRight(pair<Mint, Mint> prod, pair<Mint, Mint> left){
    // right(left) = prod
    // right = Ax + B and left = ax+b => prod = Aa x + Ab + B =>
    // A = prod.first/left.first, B = prod.second - A * left.second
    Mint A = prod.first / left.first;
    Mint B = prod.second - A * left.second;
    return {A, B};
}

pair<Mint, Mint> applyF(pair<Mint, Mint> left, pair<Mint, Mint> right){
    Mint A = left.first * right.first;
    Mint B = left.first * right.second + left.second;
    return {A, B};
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    deque<pair<Mint, Mint>> dq;
    pair<Mint,Mint> f = {1, 0};
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 0){
            //append ax + b to left
            //actually t = 1 below from dqque
            int a, b;
            cin >> a >> b;
            pair<Mint, Mint> np = {a, b};
            dq.push_back(np);
            f = applyF(np, f);
        }else if(t == 1){
            //append ax + b to right
            //actually t = 2 below from deque
            f = getRight(f, dq.front());
            dq.pop_front();
        }else if(t == 2){
            //remove from left
            //actually t = 4 below from deque
            int x;
            cin >> x;
            cout << f.first*Mint(x) + f.second << "\n";
        }else if(t == 3){
            //remove from right
            //auto ans = getLeft({A, B}, dq.back());

        }else{
            //print F(x);
            
        }
    }    
}
