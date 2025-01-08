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
        ll l, r, g;
        cin >> l >> r >> g;
        ll ml = g*((l + g - 1)/g);
        if(ml > r) cout << "-1 -1\n";
        else{
            ll mr = (r/g) * g;
            assert(mr >= ml);
            if(mr == ml){
                if(ml == g) cout << ml << " " << mr << "\n";
                else cout << "-1 -1\n";
            }else{
                for(int i=0;;i++){
                    bool ok = false;
                    ll cl = ml, cr = mr - i*g;
                    while(cr <= mr){
                        if(gcd(cl, cr) == g){
                            cout << cl << " " << cr << "\n";
                            ok = true;
                            break;
                        }else{
                            cl += g;
                            cr += g;
                        }
                    }
                    if(ok) break;
                }
            }
        }
    }
}
