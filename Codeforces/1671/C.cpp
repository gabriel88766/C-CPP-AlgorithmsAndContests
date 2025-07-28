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
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        ll cd = 0;
        ll ans = 0;
        ll sum = 0;
        for(int i=0;i<n;i++) sum += v[i];
        for(int i=n;i>=1;i--){
            if(x >= sum + cd * i){
                //so in the day "cd" I can buy "i" items
                ll ld = (x - sum) / i;
                assert(sum + ld * i <= x);
                assert(sum + (ld + 1) * i > x);
                ans += (ld - cd + 1) * i;
                cd = ld + 1;
            }
            sum -= v[i-1];
        }
        cout << ans << "\n";
    }
}
