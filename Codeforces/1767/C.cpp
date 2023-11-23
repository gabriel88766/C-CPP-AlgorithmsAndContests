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

const int N = 105;   
int p[N], sz[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
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
    sz[a] += sz[b];
}

int v[105][105];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n;
    cin >> n;
    Mint ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cin >> v[i][j];
            if(v[i][j] == 0) continue;
            if(v[i][j] == 1){
                for(int k=i;k<=j;k++) unite(i, k);
            }
        }
    }
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(get(i));
    map<int,int> mp;
    int c = 0;
    for(auto x : s) mp[x] = ++c;
    vector<int> in(c+1, -1);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(v[i][j] == 2){
                if(get(i) == get(j)){
                    cout << "0\n";
                    return 0;
                }
                in[mp[get(j)]] = max(in[mp[get(j)]], mp[get(i)]);
            }
        }
    }
    //for(int i=1;i<=c;i++) cout << i << " " << in[i] << "\n";
    vector<vector<Mint>> dp(c+1, vector<Mint>(c+1, 0));
    dp[1][0] = 2;
    for(int i=2;i<=c;i++){
        for(int j=in[i]+1;j<i;j++){
            dp[i][j] += dp[i-1][j];
        }
        for(int j=0;j<i;j++){
            dp[i][i] += dp[i-1][j];
        }
    }
    for(int i=0;i<=c;i++) ans += dp[c][i];
    cout << ans << "\n";
    
}
