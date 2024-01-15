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
    vector<ll> a(n);
    vector<Mint> ans(2*n);
    for(int i=1;i<n;i++) cin >> a[i];
    //for ancestor (leaf cant be)
    Mint cur = 1;
    vector<Mint> vec(2*n);
    vector<Mint> qt(n);
    qt[0] = 1;
    for(int j=1;j<n;j++){
        qt[j] = qt[j-1] * a[j];
    }
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            vec[j+k] += qt[j] * qt[k];
        }
    }
    for(int i=1;i<n;i++){
        Mint fat = Mint(a[i]-1)/Mint(a[i]);
    
        //for(int j=1;j<=2*(n-1);j++) ans[j] = 
        for(int j=1;j<=2*(n-i);j++){
            Mint curv = vec[j];
            if(j <= n-i){
                ans[j] += Mint(2) * cur * qt[j];
                vec[j] -= 2*qt[j];
            }
            ans[j] += fat * vec[j] * cur;
        }
        Mint inv = Mint(1)/Mint(a[i]);
        for(int j=0;j<n-i;j++){
            qt[j] = qt[j+1] *inv;
        }
        for(int j=1;j<=2*(n-i-1);j++){
            vec[j] = vec[j+2] *inv*inv;
        }
        
        cur *= a[i];
    }



    for(int i=1;i<=2*n-2;i++) cout << ans[i]/2 << " ";
    cout << "\n";
}
