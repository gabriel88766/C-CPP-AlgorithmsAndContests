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
        ll c, x;
        cin >> c >> x;
        //check 1
        bool ok = false;
        if(c >= x){
            ll dif = c - x;
            if(dif % 2 == 0){
                ll val = dif / 2;
                if((val & c) == val){
                    ok = true;
                    cout << ((1LL << 40) | val) << "\n";
                }
            }
        }
        if(!ok){
            ll xorn = c ^ x;
            if(xorn > x){
                ok = true;
                cout << xorn << "\n";
            }
        }
        if(!ok){
            cout << "-1\n";
        }
    }
}
