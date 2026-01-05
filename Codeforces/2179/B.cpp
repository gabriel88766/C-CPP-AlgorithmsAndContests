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
        int n, ans = 0;
        cin >> n;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=2;i<=n;i++) ans += abs(v[i] - v[i-1]);
        int mx = abs(v[2] - v[1]);
        for(int i=2;i<n;i++) mx = max(mx, abs(v[i+1]-v[i]) + abs(v[i] - v[i-1]) - abs(v[i+1] - v[i-1]));
        mx = max(mx, abs(v[n] - v[n-1]));
        cout << ans-mx << "\n";
    }
}
