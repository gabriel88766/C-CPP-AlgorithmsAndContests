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
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        reverse(v.begin(), v.end());
        ll lo = 1, hi = 1000000000000LL, mid;
        while(lo != hi){
            mid = lo + (hi - lo)/2;
            ll S = 0;
            for(ll i=0;i<n;i++){
                if(v[i] <= mid){
                    ll u = mid - S - v[i];
                    S += min((u/(n-i) + 1), k);
                }
            }
            if(S < mid) hi = mid;
            else lo = mid+1;
        }
        cout << lo << "\n";
    }
}
