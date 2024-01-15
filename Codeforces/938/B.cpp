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
    int n;
    cin >> n;
    vector<int> v(n+2);
    for(int i=1;i<=n;i++) cin >> v[i];
    int ans = INF_INT;
    v[0] = 1;
    v[n+1] = 1000000;
    for(int i=0;i<=n;i++){
        ans = min(ans, max(v[i]-1, 1000000-v[i+1]));
    }

    cout << ans << "\n";
}
