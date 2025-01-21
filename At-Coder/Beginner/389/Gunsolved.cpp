#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll MOD = 998244353;

struct Mint{
    const long long MOD = 1'000'000'007;
    long long v;
    Mint(){ v = 0;}
    Mint(long long u){ v = (u >= 0 ? u % MOD : u % MOD + MOD);}
    Mint pow(long long u){
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
    Mint operator= (Mint u) {this->v = u.v; return *this;}
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
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

struct Comb{
    vector<Mint> fat, invfat;
    int N;
    Comb(int maxn){ //MOD must be prime
        N = maxn;
        for(int i=0;i<N;i++){
            fat.push_back(Mint(1));
            invfat.push_back(Mint(1));
        }
        for(int i=1;i<N;i++){
            fat[i] = fat[i-1]*i;
        }
        invfat[N-1] = 1/fat[N-1];
        for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
    }
    Mint nCr(int a, int b){
        return fat[a]*invfat[a-b]*invfat[b];
    }
};


vector<int> cur;
vector<vector<int>> vc;
void helpf(int val){
    if(val == 0){
        vc.push_back(cur);
        return;
    }
    for(int i=1;i<=val;i++){
        cur.push_back(i);
        helpf(val - i);
        cur.pop_back();
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n = 30;
    cin >> n >> MOD;
    Comb cb(n*n);
    helpf(n/2);
    Mint cte = cb.nCr(29, 14); //choose vertices for each 
    vector<Mint> wc1(vc.size()), wc2(vc.size());
    for(int i=0;i<vc.size();i++){
        wc1[i] = 1;
        int ms = n/2;
        for(int j=0;j<vc[i].size();j++){
            wc1[i] *= cb.nCr(ms , vc[i][j]);
            ms -= vc[i][j];
        }
        wc2[i] = 1;
        ms = n/2 - 1;
        for(int j=1;j<vc[i].size();j++){
            wc2[i] *= cb.nCr(ms, vc[i][j]);
            ms -= vc[i][j];
        }
    }
    ll cnt = 0;
    vector<Mint> fxe(n*n, 0);
    for(int ii=0;ii<vc.size();ii++){
        auto &v = vc[ii];
        for(int jj=0;jj<vc.size();jj++){
            auto &u = vc[jj];
            if(u[0] != 1) break;
            int dif = u.size() - v.size();
            if(dif == 1 || dif == 0){
                int i = 0, j = 0;
                int xe = 0;
                for(int k=0;;k++){
                    if(i == v.size() || j == u.size()) break;
                    int mn = k & 1 ? u[j] : v[i];
                    int mx = v[i] * u[j];
                    xe += v[i] * u[j] - (k & 1 ? u[j] : v[i]);
                    if(k & 1) i++;
                    else j++;
                }
                for(int k=0;k<v.size();k++){
                    xe += (v[k] * (v[k]-1))/2;
                }
                for(int k=0;k<u.size();k++){
                    xe += (u[k] * (u[k]-1))/2;
                }
                // cout << xe << " - ";
                for(auto x : v) cout << x << " ";
                cout << " - ";
                for(auto x : u) cout << x << " ";
                cout << " - ";
                cout << wc1[ii] << " " << wc2[jj] << "\n";
                fxe[xe] += wc1[ii] * wc2[jj];
            }
        }
    }
    int mx = (n * (n-1))/2;
    vector<Mint> ans(n*n, 0);
    for(int i=n-1;i<=mx;i++){
        for(int je=0;je<=mx;je++){
            if(n-1 + je >= i){
                ans[i] += fxe[je] * cb.nCr(je, i - n + 1);
            }
        }
        cout << ans[i] << " ";
    }
}
