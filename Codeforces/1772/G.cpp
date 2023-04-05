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
        ll x, y;

        cin >> n >> x >> y;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(), a.end());

        vector<ll> win(n+1);
        win[0] = 0;
        for(int i=0;i<n;i++){
            if(i == 0) win[i+1] = a[i];
            else{
                win[i+1] = max(win[i], a[i]-i);
            }
        }
        ll ans = 0;
        while(true){
            auto it = (lower_bound(win.begin(), win.end(), x+1)-1);
            int pos = it - win.begin();
            if(x + pos >= y || pos == n){
                ans += (y-x);
                break;
            }
            if(pos - (n-pos) <= 0){ //impossible
                ans = -1;
                break;
            }
            ll jmp = pos - (n-pos);
            ll nxt = *(it+1);
            ll goal = y-pos;
            ll stp1 = (nxt - x-1) / jmp + 1;
            ll stp2 = (goal - x - 1) / jmp + 1;
            if(stp1 < stp2){
                ans += stp1 * n;
                x += jmp * stp1;
            }else{
                x += jmp * stp2;
                ans += stp2 * n;
            }
        }
        cout << ans << "\n";
    }
}
