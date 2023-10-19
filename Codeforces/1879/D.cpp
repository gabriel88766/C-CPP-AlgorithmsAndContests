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

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    Mint ans = 0;
    for(int i=0;i<=29;i++){
        pair<Mint, int> qnt[2];
        qnt[0] = {0, 0};
        qnt[1] = {0, 0};
        Mint aux = 1 << i;
        for(int j=0;j<n;j++){
            if(v[j] & (1 << i)){
                swap(qnt[1], qnt[0]);
                qnt[0].first += qnt[0].second;
                qnt[1].first += qnt[1].second;
                qnt[1].first += 1;
                qnt[1].second += 1;
            }else{  
                qnt[0].first += qnt[0].second;
                qnt[1].first += qnt[1].second;
                qnt[0].first += 1;
                qnt[0].second += 1;
            }
            ans += qnt[1].first * aux;
        }
    }
    cout << ans << "\n";
}
