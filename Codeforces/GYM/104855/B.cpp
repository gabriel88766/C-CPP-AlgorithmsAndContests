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
        ll n, m, x, y, k;
        cin >> n >> m >> x >> y >> k;
        if(k >= 4) cout << n*m-1 << "\n";
        else if(k == 3){
            ll d = min(min(x, n-x+1), min(y, m-y+1));
            cout << n*m - d << "\n";
        }else if(k == 2){  
            ll d = min(n, m);
            ll od = min(min(x*y, x*(m-y+1)), min((n-x+1)*y, (n-x+1)*(m-y+1)));
            d = min(d, od);
            cout << n*m - d << "\n";
        }else if(k == 1){
            cout << max(max((x-1)*m, (n-x)*m), max((y-1)*n, (m-y)*n)) << "\n";
        }else{
            cout << "0\n";
        }

    }
}
