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

vector<int> divs[100005];
bool vis[100005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<int,int>> v(n+1);
    Mint ans = 0;
    for(int i=1;i<=n;i++){
         cin >> v[i].first;
         v[i].second = i;
    }
    sort(v.begin() + 1, v.end(), greater<pair<int,int>>());
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            divs[j].push_back(i);
        }
    }
    int lss = 0;
    for(int i=1;i<=n;i++){
        auto [m, ind] = v[i];
        vector<int> nowv;
        for(auto x : divs[ind]) if(!vis[x]) nowv.push_back(x);
        if(!nowv.size()) continue;
        //at least 1
        int now = nowv.size();
        assert(n-now-lss >= 0);
        Mint cur = (Mint(2).pow(now) - 1) * Mint(2).pow(n - now - lss) * m;
        //cout << now << " " << cur << " " << m << "\n";
        ans += cur;
        lss += now;
        for(auto x : divs[ind]) vis[x] = true;
    }
    cout << ans << "\n";


}
