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
    ll x, k;
    cin >> x >> k;
    ll d = 1;
    for(int i=1;i<=k;i++){
        d *= 10;
        ll r = x % d;
        if(r < d - r) x -= r;
        else x += d - r;
    }
    cout << x << "\n";
}   