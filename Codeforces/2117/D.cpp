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
        ll n;
        cin >> n;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        ll xv = 2*v[1] - v[2];
        if(xv % (n+1)) cout << "No\n";
        else{
            ll y = xv / (n + 1);
            ll x = v[1] - n * y;
            if(x >= 0 && y >= 0){
                bool ok = true;
                for(int i=1;i<=n;i++){
                    ll m1 = i, m2 = n-i+1;
                    if(m1 * x + m2 * y != v[i]) ok = false;
                }
                if(ok) cout << "Yes\n";
                else cout << "No\n";
            }else cout << "No\n";
        }
    }
}
