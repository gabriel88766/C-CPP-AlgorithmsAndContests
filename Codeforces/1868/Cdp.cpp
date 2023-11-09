#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    ll v;
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

map<ll, vector<Mint>> mp;
vector<Mint> solve(ll n){
    vector<Mint> ans(200, 0);
    if(n == 0) return ans;
    ll n1 = 0;
    ll n2 = 0;
    for(int j=1;(1LL << j) <= n; j++){
        ll l = 1LL << j;
        ll r = l + (1LL << j) - 1;
        if(r > n){
            r = n;
            n1 += min(r-l+1, 1LL << (j-1));
            n2 += max(r-l+1 - (1LL << (j-1)), 0LL);
        }else{
            n1 += 1LL << (j-1);
            n2 += 1LL << (j-1);
        }
    }
    ans[0] = 1;
    vector<Mint> t1, t2;
    if(!mp.count(n1)) t1 = mp[n1] = solve(n1);
    else t1 = mp[n1];
    if(!mp.count(n2)) t2 = mp[n2] = solve(n2);
    else t2 = mp[n2];
    for(int i=0;i<t1.size();i++) ans[i] += t1[i];
    for(int i=0;i<t2.size();i++) ans[i] += t2[i];
    vector<vector<Mint>> tt(2, vector<Mint>(200, 0));
    int sz[2];
    sz[0] = sz[1] = 0;
    for(int j=0;j<2;j++){
        ll x;
        if(j == 0) x = n1;
        else x = n2;
        for(int i=0;(1LL << i) <= x; i++){
            ll l = 1LL << i;
            ll r = l + (1LL << i) - 1;
            r = min(r, x);
            tt[j][i] += (r - l + 1);
            ans[i+1] += tt[j][i];
            sz[j]++;
        }
        
    }
    for(int i=0;i<sz[0];i++){
        if(!tt[0][i].v) break;
        for(int k=0;k<sz[1];k++){
            if(!tt[1][k].v) break;
            ans[i+k+2] += tt[1][k] * tt[0][i];
        }
    }
    
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        Mint ans = 0;
        auto cp = solve(n);
        
        set<int> s;
        for(int i=0;i<200;i++){
            if(cp[i].v != 0) s.insert(i);
        }
        for(int i=1;i<=m;i++){
            Mint cur = 0;
            Mint aux1 = i;
            Mint aux2 = i-1;
            Mint aux3 = Mint(m).pow(n-s.size());
            vector<Mint> v(s.size());
            v[s.size()-1] = aux3;
            for(int j=s.size()-2;j>=0;j--) v[j] = v[j+1]*m;
            for(int j=0;j<s.size();j++){
                cur += cp[j] * (aux1 - aux2) * v[j];
                aux1 *= i;
                aux2 *= (i-1);
            }
            ans += cur * i;
        }
        cout << ans << "\n";
    }
}
