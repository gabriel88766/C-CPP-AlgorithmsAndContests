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
        ll k;
        cin >> k;
        ll lo = 1, hi = 2e18;
        while(lo != hi){
            ll mid = lo + (hi - lo)/2;
            ll sqt = sqrt(mid);
            while(sqt*sqt > mid) sqt--;
            while((sqt+1)*(sqt+1) <= mid) sqt++;
            if(mid - sqt >= k) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
}
