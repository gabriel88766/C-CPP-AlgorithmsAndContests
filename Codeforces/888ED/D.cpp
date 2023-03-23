#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll v[] = {1,0,1,2,9,44};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, k;
    cin >> n >> k;
    ll ans = 0, aux = 1;
    for(int i=0;i<=k;i++){
        aux = 1;
        for(int j=0;j<i;j++) aux *= (n-j);
        for(int j=1;j<=i;j++) aux /= j;
        ans += aux*v[i];
    }
    cout << ans;
}
