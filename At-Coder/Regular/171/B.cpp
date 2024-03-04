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
    vector<int> v(n+1);
    bool ok = true;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(v[i] < i) ok = false;
    }
    if(ok){
        vector<int> lr(n+1);
        for(int i=1;i<=n;i++) lr[i] = i;
        Mint ans = 1;
        vector<int> v1, v2;
        set<int> s1;
        for(int i=n;i>=1;i--){
            if(v[i] == i){
                v1.push_back(i);
                s1.insert(i);
            }else{
                lr[v[i]] = i;
            }
        }
        bool ok = true;
        for(int i=1;i<=n;i++){
            if(!s1.count(v[i])) ok = false;
        }
        if(!ok){
            cout << "0\n";
            return 0;
        }
        for(auto x : v1) v2.push_back(lr[x]);
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int p = 0;
        for(int i=0;i<v1.size();i++){
            while(p < v2.size() && v2[p] <= v1[i]) p++;
            ans *= (p - i);
        }
        cout << ans << "\n";
    }else cout << "0\n";
}
