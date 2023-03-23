#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        v[i] %= m;
    }
    set<ll> vs1 = {0LL};
    for(int i=0;i<n/2;i++){
        set<ll> nv;
        for(auto x : vs1){
            ll aux = (x + v[i]) % m;
            nv.insert(aux);
        }
        for(auto x : nv) vs1.insert(x);
    }
    set<ll> vs2 = {0LL};
    for(int i=n/2;i<n;i++){
        set<ll> nv;
        for(auto x : vs2){
            ll aux = (x + v[i]) % m;
            nv.insert(aux);
        }
        for(auto x : nv) vs2.insert(x);
    }
    ll maxv = 0;
    for(auto x : vs1){
        maxv = max(maxv, x + *prev(vs2.lower_bound(m-x)));
    }
    cout << maxv;
}
