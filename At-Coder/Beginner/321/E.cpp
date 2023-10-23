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
    int t;
    cin >> t;
    while(t--){
        ll n, x, k;
        cin >> n >> x >> k;
        if(k == 0){
            cout << "1\n";
            continue;
        }
        if(k > 1000){
            cout << "0\n";
            continue;
        }
        int l = 63-__builtin_clzll(x);  
        ll ans = 0;
        for(int i=0;i<l;i++){
            ll f = k - (l - 2*i);
            if(f >= 61 || f < i) continue;
            
            {
                ll par = x >> (l - i);
                ll lef = par << (f - i);
                ll rig = lef + (1LL << (f - i)) - 1;
                if(lef <= n) ans += min(rig, n)-lef + 1;
            }
            if(f != i){
                ll par = x >> (l - i - 1);
                ll lef = par << (f - i - 1);
                ll rig = lef + (1LL << (f - i - 1)) - 1;
                if(lef <= n) ans -= min(rig, n)-lef + 1;
            }
            
        }
        ll f = k + l;
        if(f <= 61){
            ll lef = x << (f - l);
            ll rig = lef + (1LL << (f - l)) - 1;
            if(lef <= n) ans += min(rig, n) - lef + 1;
        }
        cout << ans << "\n";
    }
}
