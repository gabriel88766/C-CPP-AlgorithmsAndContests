#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll p10[20];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    cin >> n;
    p10[0] = 1;
    for(int i=1;i<=18;i++) p10[i] = p10[i-1] * 10;
    if(n == 1){
        cout << "0\n";
        return 0;
    }
    --n;
    for(int i=1;;i++){
        int hf = (i+1)/2;
        assert(hf <= 18);
        if(i % 2){
            ll bg = p10[hf-1];
            ll nd = p10[hf] - 1;
            if(nd - bg + 1 >= n){
                ll ans = bg + n - 1;
                string sans = to_string(ans);
                string rans = sans;
                rans.pop_back();
                reverse(rans.begin(), rans.end());
                sans += rans;
                cout << sans << "\n";
                break;
            }else{
                n -= (nd - bg + 1);
            }
        }else{
            // 10^(hf-1) => 10^hf
            ll bg = p10[hf-1];
            ll nd = p10[hf] - 1;
            if(nd - bg + 1 >= n){
                ll ans = bg + n - 1;
                string sans = to_string(ans);
                string rans = sans;
                reverse(rans.begin(), rans.end());
                sans += rans;
                cout << sans << "\n";
                break;
            }else{
                n -= (nd - bg + 1);
            }
        }
    }
}
