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
        ll n, k, x;
        string s;
        cin >> n >> k >> x >> s;
        x--;
        vector<ll> bs;
        int p = 0;
        while(p <= n){
            int px = p;
            while(px < n && s[px] == '*') px++;
            bs.push_back((px - p)*k  + 1);
            p = px + 1;
        }
        string ans;
        reverse(bs.begin(), bs.end());
        for(auto y : bs){
            ans += string(x % y, 'b');
            ans += "a";
            x /= y;
        }
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
}
