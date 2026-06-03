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

const int N = 3005; //O(N) preprocessing, O(1) query

//Using Mint
Mint fat[N], invfat[N];
void init(){ //MOD must be prime
    fat[0] = invfat[N-1] = 1;
    for(int i=1;i<N;i++){
        fat[i] = fat[i-1]*i;
    }
    invfat[N-1] = 1/fat[N-1];
    for(int i=N-2;i>=0;i--) invfat[i] = invfat[i+1] * (i + 1);
}
Mint nCr(ll a, ll b){
    assert(a >= b); //catch silly bugs
    return fat[a]*invfat[a-b]*invfat[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    init();
    while(t--){
        int n, x;
        cin >> n >> x;
        Mint p1 = x, sum = 0, pr = 0;
        Mint qt = 0;
        vector<Mint> prd(n+1);
        prd[0] = 1;
        for(int i=1;i<=n;i++){
            string s;
            cin >> s;
            int num = stoi(s.substr(1, s.size() - 1));
            Mint cv = 1;
            if(s[0] == 'x'){
                if(num != 1) qt+=1;
                cv = num;
                p1 *= num;
            }else if(s[0] == '/'){
                if(num != 1) qt+=1;
                cv = Mint(1) / num;
                p1 /= num;
            }else if(s[0] == '-'){
                sum -= num;
            }else{
                sum += num;
            }
            if(cv.v == 1) continue;
            for(int j=qt.v;j>0;j--){
                prd[j] += prd[j-1] * cv;
            }
        }

        for(int j=0;j<=qt.v;j++){
            pr += invfat[qt.v+1] * fat[j] * fat[qt.v-j] * prd[j];
        }
        cout << p1 + sum*pr << "\n";
    }
}
