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
        int n, k;
        cin >> n >> k;
        vector<ll> v(n*k+1);
        for(int i=1;i<=n*k;i++) cin >> v[i];
        ll ans = 0;
        int x = n - ((n+1)/2);
        int cnt = 0;
        sort(v.begin()+1, v.end());
        for(int i=n*k-x, cnt = 0; cnt < k; cnt++, i-=(x+1)){
            ans += v[i];
        }
        cout << ans << "\n";
    }
}
