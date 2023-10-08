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
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for(int b = 1; b <= n; b++){
        for(int q = 0; b*q <= n; q++){
            int last = min(n, b*q + b - 1);
            int first = max(b*q + k, 1);
            if(last >= first) ans += (last-first+1);
        }
    }
    cout << ans << "\n";
}
