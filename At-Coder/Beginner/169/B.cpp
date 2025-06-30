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
    ll inf = 1'000'000'000'000'000'000LL;
    // cout << inf << "\n";
    // cout << 1000000000LL * 1000000000LL << "\n";
    int n;
    cin >> n;
    ll res = 1;
    for(int i=1;i<=n;i++){
        ll x;
        cin >> x;
        if(x == 0) res = 0;
        else if(res != 0){
            if(inf/res >= x) res *= x;
            else res = inf + 1;
        }
    }
    if(res == inf + 1) res = -1;
    cout << res << "\n";
}
