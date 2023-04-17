// WA on test 6

#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ull binpow(ll a, ll b, ll m){
    a %= m;
    ull ans = 1;
    while(b){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

vector<ll> fact(ll n){
    vector<ll> ans;
    for(ll i=2;i*i<=n;i++){
        if(!(n%i)){
            ans.push_back(i);
            while(!(n%i)) n/=i;
        }
    }
    if(n!=1) ans.push_back(n);
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, m, curm;
    vector<ll> phi;
    cin >> n >> m;
    curm = m;
    phi.push_back(m);
    while(curm >= 2){
        auto facts = fact(curm);
        for(auto u: facts){
            curm -= curm/u;
        }
        phi.push_back(curm);
    }
    vector<ll> wk(n+1);
    for(int i=1;i<=n;i++){
        cin >> wk[i];
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int li;
        for(int i=l;i<=r;i++){
            li = i;
            if(phi[i-l] == 1 || wk[i] == 1){
                break;
            }
        }
        if(l == li){
            cout << wk[l] % m << "\n";
            continue;
        }
        ll x = wk[li], y = wk[li];
        bool flag = wk[li] >= 32 ? true : false;
        for(int i=li-1; i>=l; i--){
            if(flag){
                x = binpow(wk[i], x+phi[i-l+1], phi[i-l]);
            }else{
                if(pow(wk[i], y) >= 32) flag = true;
                x = binpow(wk[i], y, phi[i-l]);
                y = binpow(wk[i], y, 1000000000);
            }
        }
        cout << x << "\n";
    }
}
