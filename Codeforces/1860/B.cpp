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
        ll m, k, a1, ak;
        cin >> m >> k >> a1 >> ak;
        if((m-ak*k) <= a1){
            ll x = m-(m/k)*k;
            if(x > a1) cout << x-a1 << "\n";
            else cout << "0\n";
        }else{
            ll ttk = (m-a1)/k;
            ll fnc = ttk-ak;
            if(m-ttk*k > a1){
                if(m >= (ttk+1)*k){
                     fnc++;
                     ttk++;
                     if(m-ttk*k > a1) fnc += m-ttk*k-a1;
                }
                else fnc += m-ttk*k-a1;
            }
            cout << fnc << "\n";
        }
    }
}
