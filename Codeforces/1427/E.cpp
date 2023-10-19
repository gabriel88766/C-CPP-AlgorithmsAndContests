#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll nxt;

vector<string> ans;
void doSum(ll a, ll b){
    ans.push_back(to_string(a) + " + " + to_string(b));
}
void doXor(ll a, ll b){
    ans.push_back(to_string(a) + " ^ " + to_string(b));
}


void t1(ll x){
    char c[60];
    doSum(x, x);
    doXor(2*x, x);
    nxt = (2*x) ^ x;
}

void tx(ll x, ll mult){
    int k = 64-__builtin_clzll(x)-1;
    for(int i=0;i<k;i++){
        ll cur = x << i;
        doSum(cur, cur);
    }
    ll cur = x;
    for(int i=1;i<=k;i++){
        if(mult & (1 << i)){
            doSum(cur, x << i);
            cur += x << i;
        }
    }
    doSum(cur, x);   
    doXor(cur, x);
    doXor(cur+x, cur^x);
    for(int i=1;i<k;i++){
        doSum(1LL << i, 1LL << i);
    }
    cur = x;
    for(int i=1;i<=k;i++){
        if(x & (1 << i)){
            doXor(cur, 1LL << i);
            cur ^= 1 << i;
        }
    }
}

ll binpow(ll a, ll  b, ll  m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll x;
    cin >> x;
    int k = 64-__builtin_clzll(x);
    if(k == __builtin_popcountll(x) || (x & 2)){
        t1(x);
        x = nxt;
        k = 64-__builtin_clzll(x);
    }
    int mod = 1 << k;
    ll mult = binpow(x, mod/2 - 1, mod);
    tx(x, mult);
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << "\n";
}
