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
        ll n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        ll mid = n+1;
        vector<int> cnt(2*n+3, 0);
        ll cur = 0;
        for(auto c : s){
            if(c == '0') cur++;
            else cur--;
            cnt[cur+mid]++;
        }
        if(cur == 0){
            if(abs(x) <= n && cnt[x+mid]) cout << "-1\n";
            else cout << "0\n";
        }else{
            ll ans = 0;
            if(x == 0) ans++;
            if(abs(x) > n){
                if(abs(x-cur) < abs(x)){
                    //then is reducing, make abs(x+k*cur) <= n
                    ll lo = 1, hi = 1e9;
                    while(lo != hi){
                        ll mid = lo + (hi - lo)/2;
                        if(x > 0){
                            if(x-cur*mid <= n) hi = mid;
                            else lo = mid + 1;
                        }else{
                            if(x - cur*mid >= -n) hi = mid;
                            else lo = mid + 1;
                        }
                    }
                    x -= cur * lo;
                }
            }
            while(abs(x) <= n){
                ans += cnt[x+mid];
                x -= cur;
            }
            
            cout << ans << "\n";
        }
    }
}
