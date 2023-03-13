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
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    ll ans = 1;
    for(int i=1;i<=n;i++) ans = (ans * i) % MOD;
    for(int i=1;i<=m;i++) ans = (ans * i) % MOD;
    if(n == m) ans = (ans * 2 ) % MOD;
    if(abs(n-m) > 1) cout << "0\n";
    else cout << ans;
}
