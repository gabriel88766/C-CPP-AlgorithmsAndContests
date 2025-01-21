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
        int n, k, l;
        cin >> n >> k >> l;
        l = 2 * l;
        k = 2 * k;
        int ans = INF_INT;
        int tm = 0, cr = 0; 
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            x = 2 * x;
            if(x <= cr){
                x = min(x + tm, cr);
                cr = x + k;
                if(cr >= l) ans = min(ans, tm);
                else ans = min(ans, tm + l - cr);
            }else{
                int dif = x - cr;
                if(dif <= tm) cr += k;
                else{
                    if(i == 0){
                        //init.
                        cr = k;
                        tm = x;
                    }else{
                        int mv = (dif - tm) / 2;
                        tm += mv;
                        cr += mv + k;
                    }
                }
                if(cr >= l) ans = min(ans, tm);
                else ans = min(ans, tm + l - cr);
            }
        }
        cout << ans << "\n";
    }
}
