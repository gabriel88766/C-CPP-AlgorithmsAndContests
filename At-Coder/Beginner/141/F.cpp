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
    int n;
    cin >> n;
    vector<ll> v(n);
    ll x1 = 0;
    for(int i=0;i<n;i++){
         cin  >> v[i];
         x1 ^= v[i];
    }
    set<ll> s;
    for(int i=0;i<n;i++){
        ll cur = v[i];
        cur &= (~x1);
        while(cur){
            ll x = 63-__builtin_clzll(cur);
            auto it = s.lower_bound((1LL << x));
            if(it != s.end() && __builtin_clzll(cur) == __builtin_clzll(*it) ){
                cur ^= *it;
            }else break;
        }
        if(cur) s.insert(cur);
    }
    if(s.size() == 0){
        cout << x1 << "\n";
        return 0;
    }
    ll ans = 0;
    for(auto it = prev(s.end()); ; --it){
        if((ans) < ((ans^*it))){
            ans = ans^*it;
        }
        if(it == s.begin()) break;
    }
    
    cout << 2*(ans&(~x1))+x1 << "\n";
}
