#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

using namespace __gnu_pbds; //required 
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 


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

const int N = 4e5+3; //O(N) preprocessing, O(1) query

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
    init();
    Mint ans;
    Mint tt;
    int cnt = 0;
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(v[i] == -1) cnt++;
    }
    tt = fat[cnt];
    //1, numbers not equal 1, ordered_set
    ordered_set<int> os;
    Mint ti = 0;
    for(int i=1;i<=n;i++){
        if(v[i] != -1){
            ti += os.order_of_key(n+1) - os.order_of_key(v[i]);
            os.insert(v[i]);
        } 
    }
    ans += tt * ti;
    //2, numbers equal -1
    if(cnt >= 2){
        Mint aux = fat[cnt]/2 * nCr(cnt, 2);
        ans += aux;
    }
    //3, numbers not equal -1 and numbers equal -1
    ordered_set<int> os2;
    for(int i=1;i<=n;i++) os2.insert(i);
    for(auto x : os) os2.erase(x);
    //numbers in -1..
    int cnt2 = 0;
    if(cnt){
        for(int i=1;i<=n;i++){
            if(v[i] == -1){
                cnt2++;
                cnt--;
            }else{
                //cnt2 numbers -1 up to index i,
                //cnt numbers -1 from index i to n;
                //opt1, v[i] < v[x], x < i (x in cnt2)
                Mint qt = os2.order_of_key(n+1) - os2.order_of_key(v[i]);
                ans += qt * Mint(cnt2) * fat[cnt+cnt2-1];
                //opt2 v[i] > v[x], x > i (x in cnt)
                qt = os2.order_of_key(v[i]);
                ans += qt * Mint(cnt) * fat[cnt+cnt2 - 1];
            }
        }
    }



    cout << ans/tt << "\n";
}
