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
    ll n, k;
    cin >> n >> k;
    k--;
    ll xx = 0;
    for(ll sum = 3;sum<=3*n;sum++){
        //a1 + a2 + a3 = sum; a1 >= 1 && a1 <= n
        ll cur = ((sum-1) * (sum-2))/2;
        if(sum >= n+3){
            cur -= 3 * ((sum-n-1) * (sum-n-2))/2;
        }
        if(sum >= 2*n+3){
            cur += 3 * ((sum-2*n-1) * (sum-2*n-2))/2;
        }
        xx += cur;
        if(k >= cur){
            k -= cur;
        }else{
            for(ll i=1;i<=n;i++){
                //a2+a3 = sum - i; (-2) a1 >= 1 && a1 <= n;
                ll xx = sum - i;
                if(xx > 2*n) continue;
                assert(xx >= 2);
                cur = min(2*n - xx + 1, xx-1);
                if(k >= cur) k -= cur;
                else{
                    for(int j=1;j<=n;j++){
                        if(xx - j <= n){
                            if(k) k--;
                            else{
                                cout << i << " " << j << " " << xx-j << "\n";
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
}
