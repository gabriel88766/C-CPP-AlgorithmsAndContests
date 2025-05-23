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
        vector<int> b1(30, 0), b2(30, 0);
        vector<int> ps(n+1, 0);
        for(int i=1;i<=n;i++){
            cin >> ps[i];
            ps[i] ^= ps[i-1];
            for(int j=0;j<30;j++){
                if(ps[i] & (1 << j)){
                    b2[j]++;
                }
            }
        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ll ln = 0, lp = 0, rn = 0, rp = 0;
            int cur = ps[i] ^ ps[i-1];
            assert(cur != 0);
            int bit = 31 - __builtin_clz(cur);
            lp = b1[bit];
            ln = i - lp;
            rp = b2[bit];
            rn = n - i + 1 - rp;
            ans += ln*rn + lp*rp;
            for(int j=0;j<30;j++){
                if(ps[i] & (1 << j)){
                    b2[j]--;
                    b1[j]++;
                }
            }
        }
        cout << ans << "\n";
    }
}
