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
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        map<int, int> mp;
        vector<int> v(n+1), mn(n+1), mx(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        int p = 1;
        for(int i=1;i<=n;i++){
            while(mp.size() < k && p <= n){
                mp[v[p]] += 1;
                p++;
            }
            if(mp.size() == k) mn[i] = p - 1;
            else mn[i] = INF_INT;
            mp[v[i]]--;
            if(mp[v[i]] == 0) mp.erase(v[i]);
        }
        mp.clear();
        p = 1;
        for(int i=1;i<=n;i++){
            while(mp.size() <= k && p <= n){
                mp[v[p]] += 1;
                p++;
            }
            if(mp.size() == k + 1) mx[i] = p - 1;
            else mx[i] = p;
            mp[v[i]]--;
            if(mp[v[i]] == 0) mp.erase(v[i]);
        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            mx[i]--;
            // cout << i << " " << mn[i] << " " << mx[i] << "\n";
            int cl = max(l, mn[i] - i + 1);
            int cr = min(r, mx[i] - i + 1);
            if(cr >= cl) ans += cr - cl + 1;
        }
        cout << ans << "\n";
    }
}
