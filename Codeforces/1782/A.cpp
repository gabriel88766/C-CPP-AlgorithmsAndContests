#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int w,d,h,a1,b1,a2,b2,ans = INF_INT, posans;
        cin >> w >> d >> h;
        cin >> a1 >> b1 >> a2 >> b2;
        posans = h + a1 + a2 + abs(b2-b1);
        ans = min(ans, posans);
        posans = h + 2 * w - a1 - a2 + abs(b2-b1);
        ans = min(ans, posans);
        posans = h + b1 + b2 + abs(a1-a2);
        ans = min(ans, posans);
        posans = h + 2 * d - b1 - b2 + abs(a1-a2);
        ans = min(ans, posans);

        cout << ans << "\n";
    }
}
