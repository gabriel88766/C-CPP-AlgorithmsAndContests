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
        int n;
        cin >> n;
        ll ps = 0;
        map<ll, ll> mp;
        mp[0] = 0;
        int l = -1;
        int ans = 0;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            ps += x;
            if(mp.count(ps)){
                if(mp[ps] >= l){
                    ans++;
                    l = i;
                }
            }
            mp[ps] = i;
        }
        cout << ans << "\n";
    }
}
