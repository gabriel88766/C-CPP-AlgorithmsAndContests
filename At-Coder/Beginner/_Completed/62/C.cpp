#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll H, W;
    ll ans;
    cin >> H >> W;
    if(H%3 && W%3){
        ans = min(H, W);
        //for H
        ll opt1 = H/3, opt2 = H/3+1;
        ll S1 = opt1*W;
        ll S2 = (W/2)*(H-opt1);
        ll S3 = (H-opt1)*W - S2;
        ll diff = max(abs(S2-S1), max(abs(S3-S1), abs(S3-S2)));
        ans = min(ans, diff);
        S1 = opt2 * W;
        S2 = (W/2)*(H-opt2);
        S3 = (H-opt2)*W - S2;
        diff = max(abs(S2-S1), max(abs(S3-S1), abs(S3-S2)));
        ans = min(ans, diff);
        //for W
        opt1 = W/3, opt2 = W/3+1;
        S1 = opt1*H;
        S2 = (H/2)*(W-opt1);
        S3 = H*(W-opt1)-S2;
        diff = max(abs(S2-S1), max(abs(S3-S1), abs(S3-S2)));
        ans = min(ans, diff);
        S1 = opt2*H;
        S2 = (H/2)*(W-opt2);
        S3 = H*(W-opt2)-S2;
        diff = max(abs(S2-S1), max(abs(S3-S1), abs(S3-S2)));
        ans = min(ans, diff);
        cout << ans;
    }else cout << "0";
}
