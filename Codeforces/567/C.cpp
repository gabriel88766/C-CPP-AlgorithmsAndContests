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
    map<int, ll> m1, m2, m3;
    if(k != 1){
        ll ans = 0;
        ll cnt0 = 0;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            if(x == 0){
                cnt0++;
                continue;
            }
            m1[x]++;
            if(x % k == 0){
                if(m1.count(x / k)) m2[x] += m1[x / k];
                if(m2.count(x / k)) m3[x] += m2[x / k];
            }
        }
        if(cnt0 >= 3) ans += (cnt0 * (cnt0-1) * (cnt0-2)) / 6;
        for(auto [k, v] : m3) ans += v;
        cout << ans << "\n";
    }else{
        map<int, ll> mp;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            mp[x]++;
        }
        ll ans = 0;
        for(auto [k, v] : mp){
            if(v >= 3){
                ans += (v * (v-1) * (v-2)) / 6;
            }
        }
        cout << ans << "\n";
    }
}
