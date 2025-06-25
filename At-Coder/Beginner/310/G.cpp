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
    ll gcd_euclid(ll a, ll b, ll &x, ll &y){ //solves ax+by = g where g = gcd(a,b)
        if(b == 0){ //meaning 1 * a - 0 * 0 = a, (gcd)
            x = 1; y = 0;
            return a;
        }
        ll d = gcd_euclid(b, a % b, y, x); //if b > a then this step reverses it
        y -= x * (a/b); 
        return d;
    }
    friend Mint operator* (Mint a, Mint const &b){ return a *= b;}
    friend Mint operator/ (Mint a, Mint const &b){ return a /= b;}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    /*Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}*/
    Mint operator/= (Mint u){ //division , MOD not prime, u.v must be coprime with MOD.
        ll x, y;
        ll g = gcd_euclid(u.v, MOD, x, y);
        assert(g == 1);
        (*this) *= x; 
        return *this;
    }
    bool operator== (const Mint u) const { return v == u.v;}
    bool operator!= (const Mint u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 2e5+3;
int a[N], b[N], in[N];
bool vis[N];
deque<Mint> allp[N];
Mint ans[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        in[a[i]]++;
    }
    for(int i=1;i<=n;i++) cin >> b[i];
    vector<int> vx;
    for(int i=1;i<=n;i++){
        allp[i].push_back(0);
        if(in[i] == 0){
            vx.push_back(i);
        }
    }
    Mint ik = Mint(1)/k;
    for(int i=1;i<=n;i++) {
        ans[i] -= b[i] *ik;
    }
    while(vx.size()){
        int u = vx.back();
        vx.pop_back();
        vis[u] = true;
        in[a[u]]--;
        if(in[a[u]] == 0) vx.push_back(a[u]);
        ans[u] += allp[u][0] + b[u] * ik;
        if(allp[u].size() == k + 1){
            allp[u][0] -= allp[u][k];
            allp[u].pop_back();
        } 
        Mint x = allp[u][0];
        allp[u].pop_front();
        allp[u].push_front(b[u] * ik);
        allp[u].push_front(allp[u][0] + x);
        if(allp[u].size() > allp[a[u]].size()) allp[u].swap(allp[a[u]]);
        for(int i=0;i<allp[u].size();i++){
            allp[a[u]][i] += allp[u][i];
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vector<int> cc;
            int j = i;
            cc.push_back(j);
            j = a[j];
            vis[j] = true;
            while(j != i){
                vis[j] = true;
                cc.push_back(j);
                j = a[j];
            }
            int sz = cc.size();
            vector<Mint> ax(sz);
            for(int j=0;j<sz;j++){
                // cout << cc[j] << " ";
                allp[cc[j]][0] = b[cc[j]] * ik;
                for(int u=0;u<allp[cc[j]].size();u++){
                    // if(sz == 1){
                        // ax[0] += (k + 1 - u) * allp[cc[j]][u];
                        // continue;
                    // }
                    ll r = (k - u) % sz;
                    ll q = (k - u) / sz;
                    ll pl = (j + r) % sz;
                    if(pl >= j){
                        ax[0] += q *  allp[cc[j]][u];
                        ax[j] += allp[cc[j]][u];
                        if(pl + 1 < sz) ax[pl + 1] -=  allp[cc[j]][u];
                    }else{
                        ax[0] += (q+1)*allp[cc[j]][u];
                        ax[pl+1] -=  allp[cc[j]][u];
                        ax[j] +=  allp[cc[j]][u];
                    }
                }
            }
            for(int j=0;j<sz;j++){
                if(j != 0) ax[j] += ax[j-1];
                ans[cc[j]] += ax[j];
            }
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}       
