#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
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



vector<vector<ll>> pows(65, vector<ll> (65, 0));
ll maxv = INF_LL;

Mint sum(ll b, ll l, ll r){
    Mint ans = 0;
    ll ind = 0;
    while(pows[b][ind] <= l/b) ind++;
    while(pows[b][ind] <= r/b){
        assert(ind <= 64);
        ans += Mint((pows[b][ind+1] - max(l, pows[b][ind]))) * Mint(ind);
        ind++; 
        
    }
    ans += Mint(r - max(l, pows[b][ind])+1LL) * Mint(ind);
    return ans;
}

Mint sum(ll l, ll r){
    Mint ans = 0;
    ll ind = 0;
    for(int i=0; pows[2][i] <= l; i++){
        ind = i;
    }
    while(pows[2][ind+1] <= r){
        ans += sum(ind, max(l, pows[2][ind]), pows[2][ind+1]-1LL);
        ind++; 
    }
    ans += sum(ind, max(l, pows[2][ind]), r);
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //init
    for(ll i = 2; i <= 63; i++){
        pows[i][0] = 1;
        int p = 0;
        while(maxv/pows[i][p] >= i){
            pows[i][p+1] = pows[i][p] * i;
            p++;
        }
    }
    int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        cout << sum(l, r) << "\n";
    }
}
