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
    Mint(ll u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
        if(u < 0) return (Mint(1)/v).pow(-u);
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

vector<vector<int>> pcs;
vector<int> cur;
int n;
void generate(){
    if(cur.size() == n){
        vector<int> cnt(n+1);
        for(auto x : cur) cnt[x]++;
        int mx = 0;
        for(int i=1;i<=n;i++) if(cnt[i] != 0) mx = i;
        bool ok = true;
        for(int i=1;i<=mx;i++) if(cnt[i] == 0) ok = false;
        if(ok) pcs.push_back(cur);
        return;
    }
    for(int i=1;i<=n;i++){
        cur.push_back(i);
        generate();
        cur.pop_back();
    }
}
ll a[10];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("out", "w", stdout); //test input
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    generate();
    Mint ans = 0;
    for(auto vec : pcs){
        vector<int> dp(n+1, INF_INT);
        dp[0] = 0;
        int mx = 0;
        for(auto x : vec){
            auto it = lower_bound(dp.begin(), dp.end(), x);
            *it = x;
            mx = max(mx, (int)(it - dp.begin()));
        }
        vector<pair<int, int>> ord = {{0, 0}};
        for(int j=0;j<n;j++) ord.push_back({vec[j], j});
        sort(ord.begin(), ord.end());
        for(int j=1;j<=n;j++){
            
        }

    }
    cout << ans << "\n";
}
