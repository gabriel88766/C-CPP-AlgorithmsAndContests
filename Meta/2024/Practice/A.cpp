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
    freopen("in", "r", stdin); //test input
    freopen("out", "w", stdout);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        ll x = *min_element(v.begin(), v.end());
        ll y = max(1, n-1);
        y = 2 * y - 1;
        x *= y;
        cout << "Case #" << i << ": ";
        if(x <= k){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}
