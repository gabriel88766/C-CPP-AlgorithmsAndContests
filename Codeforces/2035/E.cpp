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
        ll x, y, z, k;
        cin >> x >> y >> z >> k;
        ll xd = 0;
        ll ans = INF_LL;
        for(ll xx = 0; xd <= z;xx++){ 
            ll op1 = xx * k;// + ?? increase from 0 to k-1
            ll op2 = xx;// + ?? deal (z-xd + op1 - 1)/(op1)
            ll A = z - xd;
            ll bg = op1 > 0 ? op1 : 1;
            while(bg < op1 + k){
                ll aux = (A + bg - 1)/bg;
                ans = min(ans, bg * x + (aux + op2) * y);
                if(aux != 1){ // aux = 1 is minimal, bg >= A
                    for(ll j=k/2;j>=1;j>>=1){
                        while(bg + j < op1 + k && (A + bg + j - 1) / (bg + j) == aux) bg += j;
                    }
                    bg++;
                }else break;
            }
            
            /*if(k <= 100){
                for(int j=0;j<k;j++){
                    ll c1 = (op1 + j);
                    if(!c1) continue;
                    ll cur = c1 * x + (op2 + (z-xd+c1-1)/c1) * y;
                    ans = min(ans, cur);
                }
            }*/
            // need increase something between 0 and k-1
            // need to deal dmg (z-xd) in total
            xd += (xx+1) * k;
        }
        cout << ans << "\n";
    }
}
