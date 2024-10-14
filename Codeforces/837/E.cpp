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
    ll a, b;
    cin >> a >> b;
    vector<ll> dvs;
    for(ll i=1;i*i<=a;i++){
        if(!(a % i)){
            if(i*i != a) dvs.push_back(a/i);
            dvs.push_back(i);
        }
    }
    sort(dvs.begin(), dvs.end());
    ll ans = 0;
    while(b){
        ll g = gcd(a, b);
        if(g == a){
            ans += b/g;
            break;
        }
        ll mv = INF_LL;
        for(auto d : dvs){
            if(d <= g) continue;
            if(d % g) continue;
            mv = min(mv, (b % d) / g);
        }
        
        if(b <= 0) break;
        ans += mv;
        b -= mv * g;
    }
    cout << ans << "\n";
}
