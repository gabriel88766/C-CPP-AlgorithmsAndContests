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
    ll n, x, ans;
    cin >> t;
    while(t--){
        cin >> n >> x;
        ans = n;
        vector<ll> nums;
        if(x > n) cout << "-1\n";
        else{
            ll curmask = 0, cur = 1;
            for(ll cur = 1; cur <= n; cur <<= 1 ){
                curmask += cur;
                if(n & cur && !(x & cur)){
                    ans = max(ans, (n & (~curmask)) + cur*2);
                    if((ans & n) < x){
                        ans = -1;
                        break;
                    } 
                }else if(!(n & cur) && x & cur){
                    ans = -1;
                    break;
                }
                
            }
            
            cout << ans << "\n";
        }
    }
}
