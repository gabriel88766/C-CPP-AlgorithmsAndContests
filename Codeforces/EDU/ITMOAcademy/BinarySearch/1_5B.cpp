#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll lo=1, hi=1e12, mid, n, k;
    cin >> n >> k;
    ll goal = k;
    while(lo < hi){
        mid = (lo+hi)/2;
        ll cnt = 0;
        for(int i=1;i<=n;i++){
            cnt += min(mid/i, n);
        }
        if(cnt >= goal) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
}