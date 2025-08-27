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
    vector<pair<ll, ll>> nums;
    ll cn = 1;
    for(int i=0;i<=18;i++){
        nums.push_back({cn, i});
        cn *= 3;
    }
    int t;
    cin >> t;
    // reverse(nums.begin(), nums.end());
    while(t--){
        ll n;
        cin >> n;
        ll ans = 0;
        for(auto [cs, j] : nums){
            int x = n % 3;
            ans += x * (cs * 3 + j * (cs/3));
            n /= 3;
        }
        cout << ans << "\n";
    }
}
