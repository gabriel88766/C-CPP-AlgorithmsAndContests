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
        ll x, m;
        cin >> x >> m;
        //at most O(x)
        ll ans = 0;
        for(ll y = 1;y<=min(x-1, m);y++){
            ll xx = x^y;
            if(xx % y == 0) ans++;
        }
        ll aux = 0;
        if(m >= x){
            aux += (m-x)/x;
            for(ll i=m-x+1;i<=m+x;i++){
                if(i % x) continue;
                ll y = i^x;
                if(y <= m) aux++;
            }
        }

        ans += aux;
        cout << ans << "\n";
        


        
    }
}
