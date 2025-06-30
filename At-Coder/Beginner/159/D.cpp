#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll cnt[200005];
int v[200005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    cin >> n;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        cnt[v[i]]++;
    }
    for(int i=1;i<=n;i++){
        ans += (cnt[i] * (cnt[i] - 1)) / 2;
    }
    for(int i=1;i<=n;i++){
        ll cans = ans;
        cans -= ((cnt[v[i]]) * (cnt[v[i]] - 1)) / 2;
        cans += ((cnt[v[i]] - 1) * (cnt[v[i]] - 2)) / 2;
        cout << cans << "\n";
    }
}
