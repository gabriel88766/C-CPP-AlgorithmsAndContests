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
        ll m, n, ans = 0;
        cin >> n >> m;
        for(ll b=1;b<=m;b++){
            for(ll a=b;a<=n;a += b){
                //g = gcd(a, b)
                if((a+b)%(b*gcd(a,b)) == 0) ans++;
            }
        }
        cout << ans << "\n";
    }
}
