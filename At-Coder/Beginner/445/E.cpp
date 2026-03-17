#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
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

const int N = 10000000;
int lp[N+1];
vector<int> pr;
void sieve(){
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}

int vis[N+1];
pair<int, int> mx1[N+1], mx2[N+1];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Mint ans = 1;
        vector<int> allp;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            vector<pair<int, int>> ap;
            cin >> v[i];
            int x = v[i];
            while(x != 1){
                if(ap.size() == 0 || ap.back().first != lp[x]){
                    ap.push_back({lp[x], 1});
                }else{
                    ap.back().second++;
                }
                x /= lp[x];
            }
            for(auto [pr, qt] : ap){
                if(vis[pr] == 0) allp.push_back(pr);
                while(qt > vis[pr]){
                    vis[pr]++;
                    ans *= pr;
                }
                if(qt > mx1[pr].first){
                    mx2[pr] = mx1[pr];
                    mx1[pr] = {qt, i};
                }else if(qt > mx2[pr].first){
                    mx2[pr] = {qt, i};
                }
            }
        }
        for(int i=1;i<=n;i++){
            vector<int> ap;
            int x = v[i];
            while(x != 1){
                if(ap.size() == 0 || ap.back() != lp[x]){
                    ap.push_back(lp[x]);
                }
                x /= lp[x];
            }
            Mint cans = ans;
            for(auto x : ap){
                if(mx1[x].second == i){
                    int dif = mx1[x].first - mx2[x].first;
                    while(dif--) cans /= x; 
                }
            }
            cout << cans << " ";
        }
        cout << "\n";
        for(auto x : allp){
            mx1[x] = mx2[x] = {0, 0};
            vis[x] = 0;
        }

    }
}
