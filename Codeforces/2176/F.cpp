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
    Mint(ll u){ 
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


const int N = 2e5+1;
ll mi[N], p[N];
void mobius(){ //another sieve.
    for(ll i =1; i<N;i++) mi[i] = 1;
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i; j < N; j += i){
                p[j] = 1;
                if(mi[j] != 0) mi[j]++;
            }
            for(ll j = i*i; j < N; j += i*i){
                mi[j] = 0;
            }
        }
    }
    for(ll i =1; i<N;i++){
        if(mi[i]) mi[i]--;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    mobius();
    int t;
    cin >> t;
    while(t--){
        int n, xp;
        cin >> n >> xp;
        vector<int> cnt(n+1);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            for(int j=2;j*j<=x;j++){
                if(mi[j] != 1) continue;
                while(x % (j*j) == 0) x /= j;
            }
            cnt[x]++;
        }
        vector<vector<ll>> rqnt(n+1, vector<ll>(13));
        for(int i=1;i<=n;i++){
            if(i != 1 && mi[i] == 0) continue;
            vector<ll> qnt(7, 0);
            for(int j=i;j<=n;j+=i){
                if(cnt[j] != 0) qnt[mi[j]] += cnt[j];
            }
            for(int j=0;j<=6;j++){
                for(int k=j;k<=6;k++){
                    ll tt;
                    if(j == k){
                        tt = qnt[j];
                        tt *= (qnt[j] - 1);
                        tt /= 2;
                    }else{
                        tt = qnt[j] * qnt[k];
                    }
                    rqnt[i][j+k] += tt;
                }
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=2;i*j<=n;j++){
                if(mi[i*j] != 0){
                    for(int k=0;k<=12;k++){
                        rqnt[i][k] -= rqnt[i*j][k];
                    }
                }
            }
        }
        Mint ans = 0;
        for(int i=1;i<=n;i++){
            if(i == 1 || mi[i] != 0){
                for(int k=0;k<=12;k++){
                    if(rqnt[i][k]){
                        // cout << i << " " << k-mi[i] << " " << rqnt[i][k] << "\n";
                        ans += Mint(k - mi[i]).pow(xp) * rqnt[i][k];
                    }
                }
            }
        }
        cout << ans << "\n";
        
    }
}   
