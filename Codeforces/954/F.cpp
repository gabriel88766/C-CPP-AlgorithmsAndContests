#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


struct Mint{
    int v;
    //static const int MOD = MOD_val;
    Mint(){ v = 0;}
    Mint(int u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
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
    Mint operator*= (Mint u){ v = ((ll)u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    Mint operator/= (Mint u){ (*this) *= u.pow(MOD-2); return *this;}
    bool operator== (const Mint u) const { return v == u.v;}
    bool operator!= (const Mint u) const { return v != u.v;}
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
            Mint cel = 0;
            for(int k=0;k<size;k++){
                cel += a[i][k] * b[k][j];
            }
            ans[i][j] = cel;
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
    ll n, m;
    cin >> n >> m;
    map<ll, vector<pair<ll, ll>>> mp;
    for(int i=0;i<n;i++){
        int a;
        ll l, r;
        cin >> a >> l >> r;
        --a;
        mp[l].push_back({a, 1});
        mp[r+1].push_back({a, -1});
    }
    mp[m].push_back({0, 1}); //closing all but the mid.
    mp[m].push_back({2, 1}); 
    ll lv = 1;
    vector<Mint> dp = {0, 1, 0};
    vector<int> cnt(3, 0);
    for(auto [x, vp] : mp){
        vector<int> op(3), np(3);
        for(int i=0;i<3;i++){
            if(cnt[i] == 0) op[i] = 1;
        }
        for(auto [a, b] : vp){
            cnt[a] += b;
        }
        for(int i=0;i<3;i++){
            if(cnt[i] == 0) np[i] = 1;
        }
        vector<vector<Mint>> mat(3, vector<Mint>(3));
        vector<vector<Mint>> trm(3, vector<Mint>(3));
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(abs(j-k) <= 1 && op[j] && op[k]){
                    mat[j][k] = 1;
                }
                if(abs(j-k) <= 1 && op[j] && np[k]){
                    trm[j][k] = 1;
                }
            }
        }
        auto res = binpow(mat, x - lv - 1);
        vector<Mint> aux(3);
        for(int j=0;j<3;j++){
            aux[j] = res[0][j] * dp[0] + res[1][j] * dp[1] + res[2][j] * dp[2];
        }
        
        for(int j=0;j<3;j++){
            dp[j] = trm[0][j] * aux[0] + trm[1][j] * aux[1] + trm[2][j] * aux[2];
        }
        lv = x;
    }
    cout << dp[1] << "\n";
}
