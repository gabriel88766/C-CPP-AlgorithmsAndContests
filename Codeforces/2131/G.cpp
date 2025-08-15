#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    int v;
    // static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(int u){ 
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

Mint xp[41];

Mint solve(int n, int k){
    if(k == 0) return 1;
    Mint ans = n;
    k--;
    for(int j=1;j<n;j++){
        if(k >= (1LL << (j-1))){
            ans *= xp[j];
            k -= (1LL << (j-1));
        }else{
            ans *= solve(j, k);
            break;
        }
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    xp[1] = 1;
    for(int i=2;i<=40;i++){
        xp[i] = i;
        for(int j=1;j<i;j++) xp[i] *= xp[j];
    }
    int t;
    cin >> t;
    while(t--){
        int n, k;
        Mint ans = 1;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        for(int i=0;i<n;i++){
            if(v[i] >= 40 || ((1LL << (v[i]-1)) > k)){
                ans *= solve(v[i], k);
                break;
            }else{
                ans *= xp[v[i]];
                k -= (1LL << (v[i]-1));
            }
        }
        cout << ans << "\n";
    }
}
