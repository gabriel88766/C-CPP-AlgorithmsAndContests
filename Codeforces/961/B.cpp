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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n+1);
    vector<int> t(n+1);
    vector<ll> ps(n+1);
    ll sum = 0, ans = 0;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        ps[i] = ps[i-1];
        cin >> t[i];
        if(t[i]) sum += a[i];
        else ps[i] += a[i];
    }
    for(int i=k;i<=n;i++){
        ans = max(ans, sum + ps[i] - ps[i-k]);
    }
    cout << ans << "\n";

    
}