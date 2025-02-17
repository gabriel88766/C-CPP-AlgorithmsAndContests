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
        ll k, x, a;
        cin >> k >> x >> a;// >> a;
        ll cl = 0;
        for(int i=1;i<=x+1;i++){
            //(k-1) * x > cl -> x > cl / (k-1)
            ll x = cl % (k-1) == 0 ? 1 : 0;
            x += (cl + k - 2) / (k-1);
            cl += x;
            if(cl > a) break;
        }
        if(cl <= a) cout << "YES\n";
        else cout << "NO\n";
    }
}
