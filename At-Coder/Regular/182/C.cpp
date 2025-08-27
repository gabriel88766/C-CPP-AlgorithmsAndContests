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
    Mint(int u){ 
        v = u % MOD;
        if (v < 0) v += MOD;
    }
    Mint pow(ll u) const{
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

vector<vector<Mint>> multiply(vector<vector<Mint>> a, vector<vector<Mint>> b){
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

vector<vector<Mint>> add(vector<vector<Mint>> a, vector<vector<Mint>> b){
    int size = a.size();
    vector<vector<Mint>> ans(size, vector<Mint>(size));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            ans[i][j] = a[i][j] + b[i][j];
        }
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
    vector<vector<vector<Mint>>> mat(17, vector<vector<Mint>>(64, vector<Mint>(64)));
    for(int i=1;i<=16;i++){
        for(int j=0;j<64;j++) mat[i][j][j] = 1;
        if(i == 2 || i == 3 || i == 5 || i == 7 || i == 11 || i == 13){
            int b;
            if(i == 2) b = 0;
            else if(i == 3) b = 1;
            else if(i == 5) b = 2;
            else if(i == 7) b = 3;
            else if(i == 11) b = 4;
            else b = 5;
            for(int j=0;j<64;j++){
                if(j & (1 << b)){
                    mat[i][j][j ^ (1 << b)] = 1;
                }
            }
        }else{
            if(i % 2 == 0) mat[i] = multiply(mat[i/2], mat[2]);
            else if(i % 3 == 0){
                assert(i == 15 || i == 9);
                mat[i] = multiply(mat[i/3], mat[3]);
            }
        }
    }
    Mint ans = 0;
    vector<vector<Mint>> cm = mat[1];
    for(int i=2;i<=m;i++){
        cm = add(cm, mat[i]);
    }
    
    for(int i=1;i<=n;i++){
        // if(i % 1000 == 0) cout << i << endl;
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                cout << cm[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        ans += cm[63][63];
        cm = multiply(cm, cm);
    }
    cout << ans << "\n";
}
