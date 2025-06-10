#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(15)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    int ps = n/2;
    double x = v[ps];
    x /= 2;
    double ans = 0;
    for(int i=0;i<n;i++){
        ans += x + v[i] - min(2*x, (double)(v[i]));
    }
    ans /= n;
    cout << fixed << setprecision(15) << ans << "\n";
}
