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
    int t;
    cin >> t;
    while(t--){
        //10^5
        int n, x;
        cin >> n >> x;
        vector<int> v(n+2, 0);
        for(int i=1;i<=n;i++) cin >> v[i];
        v[n+1] = x;
        int ans = 0;
        for(int i=1;i<=n;i++) ans = max(ans, v[i] - v[i-1]);
        ans = max(ans, 2*(v[n+1]-v[n]));
        cout << ans << "\n";
    }
}
