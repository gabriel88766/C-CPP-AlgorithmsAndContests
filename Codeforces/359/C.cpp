#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll binpow(ll a, ll  b, ll  m = MOD){
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
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    map<ll,ll> mp;
    ll s = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        s += v[i];
    }
    for(int i=0;i<n;i++){
        mp[s - v[i]]++;
    }
    ll ans;
    for(auto [k, v] : mp){
        if(v % x){
            ans = k;
            break;
        }else{
            mp[k+1] += v/x;
        }
    }
    ans = min(ans, s);
    cout << binpow(x, ans) << "\n";
}   
