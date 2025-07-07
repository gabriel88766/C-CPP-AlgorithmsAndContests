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
        int px, py, qx, qy, n;
        cin >> n >> px >> py >> qx >> qy;
        ll d1 = abs(px - qx);
        ll d2 = abs(py - qy);
        if(n == 1){
            ll x;
            cin >> x;
            if(x*x == d1*d1 + d2*d2) cout << "Yes\n";
            else cout << "No\n";
        }else{
            vector<ll> vx(n);
            for(int i=0;i<n;i++) cin >> vx[i];
            double dmn;
            double dmx = dmn = sqrt(d1*d1+d2*d2);
            for(int i=0;i<n;i++){
                double ndmn, ndmx;
                if(dmx + 0.00001 >= vx[i] && vx[i] >= dmn - 0.00001){
                    ndmn = 0;
                }else ndmn = min(abs(dmx - vx[i]), abs(dmn - vx[i]));
                ndmx = dmx + vx[i];
                dmn = ndmn;
                dmx = ndmx;
            }
            if(dmn == 0.0) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
