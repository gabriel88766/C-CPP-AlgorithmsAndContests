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
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if(a > b) swap(a, b); //b >= a
        if(x > y) swap(x, y); //y >= x
        ll lo = 0, hi = y/a;
        while(lo != hi){
            ll mid = lo + (hi - lo + 1)/2;
            ll l = 0, h = mid;
            while(l != h){
                ll m = l + (h - l)/2;
                if(m*a + (mid - m)*b > y) l = m + 1;
                else h = m;
            }
            if((mid - l) * a + l * b <= x) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << "\n";
    }
}   
