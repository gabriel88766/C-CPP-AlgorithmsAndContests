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

Mint calcDet(vector<vector<Mint>> &m){
    int n = m.size();
    Mint det = 1;
    for(int i=0;i<n;i++){
        if(m[i][i] == 0){
            int ind = -1;
            for(int j=i+1;j<n;j++){
                if(m[j][i] != 0){
                    ind = j;
                    break;
                }
            }
            if(ind == -1) return 0;
            else{
                det *= -1;
                for(int j=i;j<n;j++){
                    swap(m[i][j], m[ind][j]);
                }
            }
        }
        det *= m[i][i].pow(n-i);
        if(i != (n-1)){
            Mint inv = Mint(1)/m[i][i];
            for(int j=i;j<n;j++){
                for(int k=i;k<n;k++){
                    m[j][k] *= inv;
                }
            }
            for(int j=i+1;j<n;j++){
                for(int k=i+1;k<n;k++){
                    m[j][k] -= m[j][i] * m[i][k];
                }
            }
        }
    }
    return det;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<vector<Mint>> m(n, vector<Mint>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> m[i][j].v;
        }
    }
    cout << calcDet(m) << "\n";
}