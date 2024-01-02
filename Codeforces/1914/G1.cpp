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

const int N = 2e5+3;   
int p[N], sz[N];
int il[N], ir[N], il1[N], ir1[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1; il[i] = ir[i] = -1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    il[a] = min(il[b], il[a]);
    ir[a] = max(ir[b], ir[a]);
    sz[a] += sz[b];
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        init(n);
        vector<int> v(2*n+1);
        for(int i=1;i<=2*n;i++){
             cin >> v[i];
             if(il[v[i]] == -1) il1[v[i]] = il[v[i]] = i;
             else ir1[v[i]] = ir[v[i]] = i;
        }
        //unite
        Mint ans = 1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(get(i) == get(j)) continue;
                int a = i, b = j;
                if(il1[a] < il1[b] && il1[b] < ir1[a] && ir1[a] < ir1[b]) unite(a, b);
                if(il1[b] < il1[a] && il1[a] < ir1[b] && ir1[b] < ir1[a]) unite(a, b);
            }
        }
        vector<bool> su(n+1, true);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(get(i) == get(j)) continue;
                int a = get(i);
                int b = get(j);
                if(il[a] < il[b] && ir[b] < ir[a]) su[b] = false;
                if(il[b] < il[a] && ir[a] < ir[b]) su[a] = false;
            }
        }
        vector<bool> vis(n+1, false);
        int qt2 = 0;
        for(int i=1;i<=n;i++){
            int a = get(i);
            if(su[a] && !vis[a]){
                ans *= (2*sz[a]);
                qt2++;
                vis[a] = true;
            }
        }
        cout << qt2 << " " << ans << "\n";
    }
}
