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

vector<vector<Mint>> multMatrix(vector<vector<Mint>> a, vector<vector<Mint>> b){
    int size = a.size();
    vector<vector<Mint>> ans(size, vector<Mint>(size));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

vector<vector<Mint>> binpow(vector<vector<Mint>> a, ll b){
    int size = a.size();
    vector<vector<Mint>> ans(size,vector<Mint>(size)); //idt
    for(int i=0;i<size;i++) ans[i][i] = 1; //idt

    while(b > 0){
        if(b & 1) 
            ans = multMatrix(ans, a);
        a = multMatrix(a, a);
        b >>= 1;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n);
    vector<Mint> val(n);
    for(int i=0;i<n;i++) cin >> val[i].v;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<Mint>> mat(n, vector<Mint>(n));
    Mint inv = Mint(1)/2;
    for(int i=0;i<n;i++){
        mat[i][i] = m - Mint(adj[i].size()) * inv;
        for(auto v : adj[i]){
            mat[i][v] = inv; 
        }
    }
    Mint invm = Mint(1)/m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j] *= invm;
        }
    }
    mat = binpow(mat, k);
    for(int i=0;i<n;i++){
        Mint ans = 0;
        for(int j=0;j<n;j++) ans += mat[i][j] * val[j];
        cout << ans << "\n";
    }
}
