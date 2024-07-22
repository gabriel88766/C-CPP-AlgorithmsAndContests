#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9;
const int INF_INT = 0x3f3f3f3f;
const double PI = acos(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin);
    int ans = 0;
    for(int i=2;i<=10000;i++){
        //Following algorithm generate the continued fraction of sqrt(i) and store it in vector a
        //this fraction is periodic.
        ll a0 = sqrt(i);
        ll aa = a0;
        ll mm = 0;
        ll dd = 1;
        if(a0*a0 == i) continue; //:)
        vector<int> a, m, d;
        while(true){
            if(a.size()){
               aa = a.back();
               mm = m.back();
               dd = d.back();  
            } 
            ll nm = dd*aa - mm;
            ll nd = (i - nm*nm)/dd;
            ll na = (a0+nm)/nd;
            if(a.size() && na == a[0] && nm == m[0] && nd == d[0]) break;
            a.push_back(na);
            m.push_back(nm);
            d.push_back(nd);
        }
        if(a.size() % 2) ans++;
    }
    cout << ans << "\n";
}
