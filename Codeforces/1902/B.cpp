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
        ll n, P, l, t;
        cin >> n >> P >> l >> t;
        ll ttsk = (n+6)/7;
        ll maxp = ttsk * t + (ttsk/2 + ttsk % 2) * l;
        if(maxp > P){
            if(ttsk % 2){
                ll om = (ttsk-1) * t + (ttsk/2) * l;
                if(om < P){
                    cout << n - ttsk/2 - ttsk%2 << "\n";
                    continue;
                }
            }
            ll lo = 0, hi = ttsk/2;
            while(lo != hi){
                ll mid = lo + (hi - lo)/2;
                ll tt = 2*mid*t + mid * l;
                if(tt >= P) hi = mid;
                else lo = mid + 1;
            }
            cout << n-lo << "\n";
        }else{
            P -= maxp;
            n -= (ttsk/2 + ttsk % 2);
            n -= (P+l-1)/l;
            cout << n << "\n";
        }

    }
}
