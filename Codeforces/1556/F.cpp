#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
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


void fwht(vector<Mint> &a, int lo, int hi, int s) { 
    if(lo == (hi-1)) return;
    //w1^n = 1
    int mid = lo + (hi-lo)/2;
    fwht(a, lo, mid, s);
    fwht(a, mid, hi, s);
    for(int i = 0; lo+i < mid; i++){
        Mint x = a[lo+i];
        Mint y = a[mid+i];
        if(s == 1){
            a[lo+i] = x;
            a[mid+i] = x + y;
        }else{
            a[lo+i] = x;
            a[mid+i] = y - x;
        }
    } 
}

void multiply(vector<Mint> &a, vector<Mint> &b, int n) { //just one example of task, sometimes you don't want multiply!
    fwht(a,0,n,1);
    fwht(b,0,n,1);
    for (int i = 0; i < n; i++) a[i] = a[i]*b[i];
    fwht(a,0,n,-1);
}



Mint dp[14][14][1 << 14];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    dp[0][0][1] = 1;
    for(int i=1;i<n;i++){
        int st = 1 << i;
        vector<Mint> ans(1 << i);
        ans[0] = 1;
        for(int j=0;j<i;j++){
            vector<Mint> cur(1 << i);
            cur[0] = Mint(a[j])/Mint(a[i] + a[j]);
            Mint pw = Mint(a[i])/Mint(a[i] + a[j]);
            for(int k=1;k<(1 << i);k++){
                cur[k] = dp[i-1][j][k] * pw;
            }
            multiply(ans, cur, 1 << i);
        }
        for(int j=0;j < (1 << i);j++){
            dp[i][i][j | st] = ans[j];
            cout << ans[j] << " ";
        }
        cout << "\n";

        for(int k=0;k < i;k++){
            Mint pl = Mint(a[i])/Mint(a[i] + a[k]);
            Mint pw = Mint(a[k])/Mint(a[i] + a[k]);
            vector<Mint> v1(1 << (i+1));
            vector<Mint> v2(1 << (i+1));

            for(int j=0;j<(1 << (i+1));j++){
                v1[j] = dp[i-1][k][j];
            }
            v2[0] = pl;
            for(int j=1;j<(1 << (i+1));j++){
                v2[j] = dp[i][i][j] * pw;
            }
            multiply(v1, v2, 1 <<(i+1));
            for(int j=0;j<(1 << (i+1));j++){
                dp[i][k][j] = v1[j];
            }
        }
    }
    Mint ans = 0;
    for(int i=0;i<n;i++){
        cout << dp[n-1][i][(1 << n) - 1] << " ";
    }
    cout << "\n";
    for(int i=0;i<n;i++) ans += dp[n-1][i][(1 << n) - 1];
    cout << ans << "\n";
}

//UNSOLVED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!