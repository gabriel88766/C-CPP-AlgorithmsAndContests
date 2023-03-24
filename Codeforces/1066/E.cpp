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
    int n, m;
    cin >> n >> m;
    string a, b;
    vector<ll> add(n, 0);
    cin >> a >> b;
    ll cnt = 0;
    for(int i=0;i<m;i++){
        int ia = n-m+i;
        if(b[i] == '1') cnt++;
        if(ia >= 0 && a[ia] == '1') add[ia] = cnt;
    } 
    reverse(add.begin(), add.end());
    ll ans = 0, aux = 1;
    for(int i=0;i<n;i++){
        ans = (ans + aux * add[i]) % MOD;
        aux = (aux * 2) % MOD;
    }
    cout << ans;
}
