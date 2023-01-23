#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll m, hi = 8e18, lo = 0, mid;
    cin >> m;
    while(lo != hi){
        mid = (lo+hi)/2;
        ll sum = 0, cur;
        for(ll i=2;(i*i*i) <= mid; i++){
            cur = i*i*i;
            sum += mid/cur;
        }
        if(sum >= m) hi = mid;
        else lo = mid + 1;
    }
    ll sum = 0, cur;
    for(ll i=2;(i*i*i) <= lo; i++){
        cur = i*i*i;
        sum += lo/cur;
    }
    if(sum == m) cout << lo;
    else cout << -1;
}
