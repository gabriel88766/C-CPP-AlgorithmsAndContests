#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll sum(ll a, ll b){ //r = 1
    if(a > b) return 0;
    return ((b-a+1) * (a+b))/2;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, x, d;
    cin >> n >> x >> d;
    ll ans = 0;
    if(d != 0){
        map<ll, set<pair<ll, ll>>> mp;
        for(int i=0;i<=n;i++){
            ll st = sum(0, n-1) * d;
            ll mxS = x * i + sum(n-i, n-1) * d;
            ll mnS = x * i + sum(0, i-1) * d;
            ll mxT = x * (n - i) + st - sum(0, i-1) * d;
            ll mnT = x * (n - i) + st - sum(n-i, n-1) * d;
            ll mxx = mxS - mnT;
            ll mnx = mnS - mxT;
            int cg = mnx % (2*d);
            if(cg < 0) cg += abs(2*d);
            mp[cg].insert({min(mnx, mxx), max(mnx, mxx)});
        }
        for(auto &[k, s] : mp){
            ll lf = -INF_LL;
            for(auto &[a, b] : s){
                if(a > lf){
                    ans += (b-a)/abs(2*d) + 1;
                    lf = b;
                }else if(b > lf){
                    ans += (b - lf) / abs(2*d);
                    lf = b;
                }
            }
        }
        cout << ans << "\n";
    }else{
        //d == 0
        if(x != 0) cout << n+1 << "\n";
        else cout << 1 << "\n";
    }
    
}
