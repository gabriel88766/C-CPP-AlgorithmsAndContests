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
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    ll ans = 0;
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++) ans += v[i]*v[i];
    int k = n-m;
    for(int i=0;i<k;i++){
        ans += 2*v[i]*v[2*k-i-1];
    }
    cout << ans << "\n";
}
