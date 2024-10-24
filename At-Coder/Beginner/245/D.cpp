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
    vector<ll> a(n+1), b(m+1), c(n+m+1);
    for(int i=0;i<=n;i++) cin >> a[i];
    for(int i=0;i<=n+m;i++) cin >> c[i];
    //a[0] * b[0] = c[0].
    //a[0] * b[1] + a[1] * b[0] = c[1];
    //and so on...
    for(int i=n+m;i>=n;i--){
        //c[n+m] = a[n] * b[m]
        //c[n+m-1] = a[n] * b[m-1] + a[n-1] * b[m]
        //...
        //c[n] = a[n] *b[0] + ... + a[0] * b[n] or a[n-..]
        ll cs = 0;
        for(int j=i-n+1;j<=min(m, i);j++) cs += b[j] * a[i-j];
        b[i-n] = (c[i] - cs) / a[n];
    }
    for(int i=0;i<=m;i++) cout << b[i] << " ";
    cout << "\n";

}
