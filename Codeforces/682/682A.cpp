#include <bits/stdc++.h>
typedef long long int ll;
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
    ll ans = 0, aux1[5], aux2[5];
    cin >> n >> m;
    for(int i=0;i<5;i++){
        aux1[i] = n/5 + (n % 5 >= i ? 1 : 0);
        aux2[i] = m/5 + (m % 5 >= i ? 1 : 0);
        if(!i) aux1[i]--, aux2[i]--;
    }
    for(int i=0;i<5;i++){
        if(i) ans += aux1[i] * aux2[(5-i)];
        else ans += aux1[i] * aux2[i];
    }
    cout << ans;

}
