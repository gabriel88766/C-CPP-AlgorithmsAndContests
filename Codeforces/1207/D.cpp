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
    Mint operator/= (Mint u){ //division untested, MOD not prime, u.v must be coprime with MOD.
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

const int N = 6e5+2;
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
    init();
    int n;
    cin >> n;
    vector<pair<int,int>> v(n+1);
    vector<pair<int,int>> v1, v2;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
        v1.push_back({a, i});
        v2.push_back({b, i});
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    Mint ans = fat[n];
    Mint c1 = 1, c2 = 1, c12 = 1;
    int s = 1;
    for(int i=1;i<n;i++){
        if(v1[i].first == v1[i-1].first) s++;
        else{
            c1 *= fat[s];
            s = 1;
        }
    }
    c1 *= fat[s];
    s = 1;
    for(int i=1;i<n;i++){
        if(v2[i].first == v2[i-1].first) s++;
        else{
            c2 *= fat[s];
            s = 1;
        }
    }
    c2 *= fat[s];
    set<int> s1, s2;
    s1.insert(v1[0].second);
    s2.insert(v2[0].second);
    int p0 = 1, p1 = 1;
    while(p0 < n || p1 < n){
        while(p0 < n && v1[p0].first == v1[p0-1].first) s1.insert(v1[p0++].second);
        while(p1 < n && v2[p1].first == v2[p1-1].first) s2.insert(v2[p1++].second);
        bool ok = true;
        if(s1.size() < s2.size()){ for(auto x : s1) if(!s2.count(x)) ok = false;}
        else {for(auto x : s2) if(!s1.count(x)) ok = false;}
        if(ok){
            c12 *= fat[min(s1.size(), s2.size())];
            if(s1.size() < s2.size()){
                for(auto x : s1) s2.erase(x);
                s1.clear();
            }else{
                 for(auto x : s2) s1.erase(x);
                s2.clear();
            }
            if(!s1.size()) s1.insert(v1[p0++].second);
            else s2.insert(v2[p1++].second);
        }else{
            c12 = 0;
            break;
        }
    }
    ans -= c1 + c2;
    ans += c12;
    cout << ans << "\n";

}
