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
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        Mint ans = 0;
        vector<Mint> cp(200, 0LL);
        cp[0] = n;
        for(int i=0; (1LL << i) <= n; i++){
            ll l = 1LL << i, r = (1LL << (i+1)) - 1;
            //r = min(r, n);
            if(r <= n){
                for(int j = 0; j < i; j++){
                    cp[2*(j+1)] += Mint(r - l + 1) * Mint(1LL << j) / 2;
                }
                for(int j=0;j<i;j++){
                    for(int k=0;k<i-j;k++){
                        if(k!= 0) cp[j+1+2*k] += (Mint(1LL << k) - Mint(1LL << (k-1)))*Mint(r-l+1); 
                        else cp[j+1+2*k] += Mint(1LL << k)*Mint(r-l+1);
                    }
                }
            }else{
                r = n;
                ll aux = 0;
                for(int j = 0; j < i; j++){
                    //ll num = (r-l+1) & ~(1LL << j);  
                    aux |= (1LL << j);
                    ll num1 = (r-l+1) & ~aux;
                    ll aux2 = (r-l+1) - num1;
                    ll num2 = aux2 - (1LL << j);
                    //cerr << num1 << " " << " " << aux2 << " " << num2 << "\n";
                    if((1LL << j) <= (r-l+1)){
                        cp[2*(j+1)] += Mint(num1) * Mint(1LL << j) / 2;
                        if(num2 > 0)cp[2*(j+1)] += Mint(num2) * Mint(1LL << j);
                    }
                }
                //here ok
                for(int j=0;j<i;j++){
                    for(int k=0;k<i-j;k++){
                        if(k!= 0)cp[j+1+2*k] += (Mint(1LL << k) - Mint(1LL << (k-1)))*Mint(r-l+1); 
                        else cp[j+1+2*k] += Mint(1LL << k)*Mint(r-l+1);
                    }
                }
            }
        }
        set<int> s;
        for(int i=0;i<200;i++){
            if(cp[i].v != 0) s.insert(i);
        }
        //cp[2] += 1;
        //for(auto x : s) cout << cp[x] << " ";
        //cout << "\n";
        for(int i=1;i<=m;i++){
            Mint cur = 0;
            Mint aux1 = i;
            Mint aux2 = i-1;
            Mint aux3 = Mint(m).pow(n-s.size());
            vector<Mint> v(s.size());
            v[s.size()-1] = aux3;
            for(int j=s.size()-2;j>=0;j--) v[j] = v[j+1]*m;
            for(int j=0;j<s.size();j++){
                cur += cp[j] * (aux1 - aux2) * v[j];
                aux1 *= i;
                aux2 *= (i-1);
            }
            ans += cur * i;
        }
        cout << ans << "\n";
    }
}
