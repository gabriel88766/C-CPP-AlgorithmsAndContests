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

int pos[(1 << 19)+1];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int k;
    cin >> k;
    int n = 1 << k;
    vector<int> v(1 << k);
    for(int i=0;i< (1 << k); i++){
        cin >> v[i];
        if(v[i] != -1) pos[v[i]] = i;
    }
    Mint ans = 1;
    int cur = 1;
    for(int i=1;i<=k;i++){ //1,2,   3,4,   5,6,7,8,
        int l = (1 << (k-i))+1, r = l + (1 << (k-i)) - 1;
        int in = 1 << i;
        if(i == k) l--, in >>= 1;
        vector<int> allp;
        vector<int> cnt(n, 0);
        vector<bool> used(n, false);
        for(int j=0; j < n; j ++){
            if(v[j] >= l && v[j] <= r){
                 allp.push_back(j);
                 used[j/in] = true;
            }
            if(v[j] != -1 && v[j] < l) cnt[j/in]++;
        }
        int f = (r-l+1) - allp.size(); //fatorial to 
        bool ok = true;
        for(int j=1;j<allp.size();j++){
            if(allp[j]/in == allp[j-1]/in) ok = false;
        }

        if(ok){
            for(int j=f;j>=1; j--){
                ans *= Mint(j);
            }
            if(i != k){
                for(int j=0;j<n/in;j++){
                    if(!used[j]){
                        ans *= Mint(2-cnt[j]);
                    }
                }
            }
        }else{
            ans = 0;
            break;
        }
    }
    cout << ans << "\n";
}
