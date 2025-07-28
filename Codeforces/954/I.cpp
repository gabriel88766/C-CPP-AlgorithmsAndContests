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

// if MOD 786433, w = 5 and change to 1 << 18
void ntt(vector<Mint> &a, int n, int s) { //31^(2^23) == 1 (mod 998244353), so, for example, if n = 2^16, w1 = 31^(2^7)
    Mint w1 = 31;
    for(int i = n; i < (1 << 23); i <<= 1) w1 *= w1;
    for (int i=0, j=0; i<n; i++) {
        if (i>j) swap(a[i], a[j]);
        for (int l=n/2; (j^=l) < l; l>>=1);
    }
    //w1^n = 1
    for(int i = 1; (1<<i) <= n; i++){
        int M = 1 << i;
        int K = M >> 1;
        Mint wn = w1.pow( n + s*(n/M)); 
        for(int j = 0; j < n; j += M) {
            Mint w = 1;
            for(int l = j; l < K + j; ++l){
                Mint t = w*a[l + K];
                a[l + K] = a[l] - t;
                a[l] = a[l] + t;
                w *= wn;
            }
        }
    }
}

int p[6], sz[6];

void init(){
    for(int i=0;i<6;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}

vector<pair<int, int>> pos = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5}};
int dp[1 << 15]; //test all 2^15 possibilities
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    assert(pos.size() == 15);
    for(int i=1;i<(1 << 15); i++){
        init();
        for(int j=0;j<15;j++){
            if(i & (1 << j)){
                unite(pos[j].first, pos[j].second);
            }
        }
        vector<bool> us(6, false);
        int cnt = 0;
        for(int j=0;j<6;j++){
            if(!us[get(j)]){
                us[get(j)] = true;
                cnt++;
            }
        }
        dp[i] = 6 - cnt;
    }
    string s, t;
    cin >> s >> t;
    int n = 1 << 18;
    vector<vector<Mint>> a(6, vector<Mint>(n)), b(6, vector<Mint>(n));
    for(int j=0;j<s.size();j++){
        a[s[j]-'a'][j] = 1;
    }
    for(int j=0;j<t.size();j++){
        int ind = t.size() - j - 1;
        b[t[j]-'a'][ind] = 1;
    }
    for(int j=0;j<6;j++){
        ntt(a[j], n, 1);
        ntt(b[j], n, 1);
    }
    vector<int> ans(n);
    
    int fi = t.size() - 1;
    int li = s.size() - 1;
    for(int i=0;i<pos.size();i++){
        int i1 = pos[i].first, i2 = pos[i].second;
        vector<Mint> cur(n), cur2(n);
        for(int j=0;j<n;j++){
             cur[j] = a[i1][j] * b[i2][j];
             cur2[j] = a[i2][j] * b[i1][j];
        }
        ntt(cur, n, -1);
        ntt(cur2, n, -1);
        Mint inv  = Mint(1)/n;
        for (int j = 0; j < n; j++){
            cur[j] *= inv;
            cur2[j] *= inv;
        }
        for(int j=fi;j<=li;j++){
            if(cur[j].v != 0 || cur2[j].v != 0){
                ans[j] |= (1 << i);
            }
        }
    }
    for(int j=fi;j<=li;j++) cout << dp[ans[j]] << " ";
}
