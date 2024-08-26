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
    ll n, H;
    cin >> n >> H;
    ll lo = 1, hi = 2e9;
    while(lo != hi){
        ll mid = lo + (hi - lo)/2;
        if((mid * (mid + 1))/2 >= n) hi = mid;
        else lo = mid + 1;
    }
    if(lo <= H) cout << lo << "\n";
    else{
        //double triangle
        ll fac = (H * (H-1))/2;
        ll lo = 1, hi = 2e9;
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;
            if(mid * mid - fac >= n) hi = mid;
            else lo = mid + 1;
        }
        //opt1 = H H+1 ... x-1 x x-1 ... 1
        //opt2 = H H+1 ... x-1 x-1 ... 1
        if(lo*(lo-1) - fac >= n) cout << 2*lo - H - 1 << "\n";
        else cout << 2*lo - H << "\n";
    }
}
