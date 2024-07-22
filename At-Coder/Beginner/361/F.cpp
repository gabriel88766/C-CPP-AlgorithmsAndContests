#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll pownaive(ll n, ll p){
    ll ans = 1;
    for(int i=0;i<p;i++){
        if(INF_LL/ans >= n) ans *= n;
        else ans = INF_LL;
    }
    return ans;
}

ll mysqrt(ll n){
    ll ans = 0;
    for(ll jmp = 1e9; jmp >= 1; jmp >>= 1){
        while((ans+jmp) * (ans+jmp) <= n) ans += jmp;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, ans = 0;
    cin >> n;
    vector<ll> v;
    for(int i=3;i<=60;i++){
        for(int j=1;;j++){
            ll x = pownaive(j, i);
            if(x <= n) v.push_back(x);
            else{
                break;
            }
        }
    }
    ans = mysqrt(n);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(auto x : v){
        ll cur = mysqrt(x);
        if(cur*cur != x) ans++; 
    }
    cout << ans << "\n";
}
