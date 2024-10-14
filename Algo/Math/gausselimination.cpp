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

//Only tested in 1155E
vector<Mint> gauss(vector<vector<Mint>> &mat, vector<Mint> &res){
    //mat[i][0] * x0 + mat[i][1] * x1 + ... + mat[i][m] * xm = res[i] for all i;
    int n = mat.size();
    int m = mat[0].size();
    vector<Mint> ans(m, 0);
    int c = 0, rm = n-1;
    for(int i=0;i<n;i++){
        int ind = -1;
        while(ind == -1 && c < m){
            for(int j=i;j<n;j++){
                if(mat[j][c].v != 0){
                    ind = j;
                    break;
                }
            }
            if(ind == -1) c++;
        }
        if(ind != -1){
            swap(mat[ind], mat[i]);
            for(int j=i+1;j<n;j++){
                if(mat[j][c].v != 0){
                    Mint mult = mat[j][c] / mat[i][c];
                    for(int k=c;k<m;k++){
                        mat[j][k] -= mult * mat[i][k];
                    }
                    res[j] -= mult * res[i];
                }
            }
            c++;
        }else{
            //well, ind still = -1, so c = m
            //system has solution if and only if all cells below are 0
            assert(c == m);
            for(int j=i;j<n;j++){
                if(res[j].v != 0){
                    return ans; //impossible
                }
            }
            //possible
            rm = i-1;
            break;
        }
    }
    c = m-1;
    for(int j=rm;j>=0;j--){
        int fc = -1;
        for(int k=0;k<m;k++){
            if(mat[j][k].v != 0){
                fc = k;
                break;
            }
        }
        for(int k=fc+1;k<=c;k++) ans[k] = 0;
        Mint val = 0;
        for(int k=fc+1;k<m;k++) val += ans[k] * mat[j][k];
        val = res[j] - val;
        val /= mat[j][fc];
        ans[fc] = val;
        c = fc - 1;
    }
    return ans;

}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<vector<Mint>> mt(n,vector<Mint>(m));
    vector<Mint> res(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll x;
            cin >> x;
            mt[i][j] = x;
        }
    }
    for(int j=0;j<n;j++){
        ll x;
        cin >> x;
        res[j] = x;
    }
    auto ans = gauss(mt, res);
}
