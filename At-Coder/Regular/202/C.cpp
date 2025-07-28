#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
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


const int N = 2e5+3;
Mint Re[N], invRe[N];
Mint po10[N];
vector<int> dv[N];
bool in[N];

int cnt[N];

int pr[N];
int mi[N];
int aux[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i =1; i<N;i++) mi[i] = 1;
    for(ll i=2; i<N; i++){
        if(!pr[i]){
            for(ll j = i; j < N; j += i){
                pr[j] = 1, mi[j] *= -1;
            }
            for(ll j = i*i; j < N; j += i*i){
                mi[j] = 0;
            }
        }
    }
    Re[1] = 1;
    po10[0] = 1;
    invRe[1] = 1;
    for(int i=2;i<N;i++){
        po10[i-1] = po10[i-2] * 10;
        Re[i] = Re[i-1] + po10[i-1];
        invRe[i] = Mint(1)/Re[i];
    }
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            dv[j].push_back(i);
        }
    }
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    Mint ans = 1;
    for(int i=0;i<n;i++){
        if(!in[v[i]]){
            in[v[i]] = true;
            for(auto x : dv[v[i]]){
                if(cnt[x] != 0) aux[x] = 0;
                else aux[x] = 1;
                cnt[x]++;
            }
            for(auto x : dv[v[i]]){
                for(auto y : dv[v[i] / x]){
                    if(y == 1) continue;
                    aux[x] += aux[x*y] * mi[y];
                }
                if(aux[x] > 0){
                    for(int j=0;j<aux[x];j++) ans *= Re[x];
                }else{
                    for(int j=0;j<abs(aux[x]);j++) ans *= invRe[x];
                }
            }


        }
        cout << ans << "\n";
    }
}
