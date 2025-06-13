#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll MOD;

struct Mint{ //MOD isn't prime, so NO division.
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
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    friend Mint operator- (Mint a, Mint const &b){ return a -= b;}
    Mint operator*= (Mint u){ v = (u.v * v) % MOD; return *this;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    Mint operator-= (Mint u){ v = (v-u.v < 0 ? v-u.v+MOD : v-u.v); return *this;}
    bool operator== (const Mint u) const { return v == u.v;}
    bool operator!= (const Mint u) const { return v != u.v;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

const int N = 505; //O(N) preprocessing, O(1) query

//Using Mint
Mint fat[N];
void init(){ //MOD must be prime
    fat[0] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
}

Mint dp[N][N];
Mint pot2[N];
Mint op2[N][N];
Mint anof[N][N];
Mint cmpss[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n >> MOD;
    init();
    dp[1][1] = 1; //basically, the first vertice.
    pot2[0] = 1;
    for(int i=1;i<=n;i++) pot2[i] = pot2[i-1] * 2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            op2[i][j] = (pot2[i] - 1).pow(j);
        }
    }
    for(int i=1;i<=n;i++){
        cmpss[i] = Mint(2).pow((i * (i-1)) /2);
    }
    for(int i=1;i<=n;i++){
        vector<int> fc;
        fc.push_back(i);
        for(int j=1;j<=i;j++){
            //anof[i][j] = i * (i-1) * (i-2) * ... (i-j + 1) / j!
            int cf = j;
            vector<int> nel;
            for(int u=2;u*u<=cf;u++){
                while(cf % u == 0){
                    nel.push_back(u);
                    cf /= u;
                }
            }
            if(cf != 1) nel.push_back(cf);
            for(auto &x : nel){
                for(auto &y : fc){
                    if(y % x == 0){
                        y /= x;
                        break;
                    }
                }
            }
            Mint cn = 1;
            for(auto &x : fc) cn *= x;
            anof[i][j] = cn;
            fc.push_back(i-j);
        }
    }
    
    for(int i=2;i<=n;i++){
        for(int sz=1;sz<=i-1;sz++){ //sz of the component ending in i
            if(i == n && sz > 1) break;
            for(int j=1;j<=i-sz;j++){ //sz of the component ending in i-sz
                if(i != n) dp[i][sz] += dp[i-sz][j] * op2[j][sz] * anof[i-1][sz] * cmpss[sz];//each of sz can be connected my 2^j - 1 other nodes
                else dp[i][sz] += dp[i-sz][j] * op2[j][sz];
            }
        }
    }
    cout << dp[n][1] << "\n";
}
