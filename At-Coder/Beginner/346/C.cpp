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
    ll n, k;
    cin >> n >> k;
    set<int> s;
    ll ans = (k * (k+1))/2;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x <= k)s.insert(x);
    }
    for(auto &y : s) ans -= y;
    cout << ans << "\n";
}
