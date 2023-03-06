#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, m;
    cin >> n >> m;
    ll grv = 1;
    for(int i=1;i<=56;i++) grv *= 2;
    for(ll i = grv; i>0; i >>= 1){
        if((m - 2*i) >= (n + i)*2) m -= 2*i, n += i;
    }
    cout << min(n, m/2);
}
