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
    ll n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll lo = 1, hi = 2e9, mid;
    while(lo != hi){
        mid = (lo+hi)/2;
        ll cs = 0;
        int p = -1;
        int val = mid - b[0];
        for(int j=n; j >= 1; j >>= 1){
            while(p+j < n && a[p+j] <= val) p += j; 
        }
        cs += p+1;
        for(int i=1;i<n;i++){
            val = mid - b[i];
            if(val <= 0) continue;
            while(p >= 0 && a[p] > val) p--;
            cs += p+1;
        }
        if(cs >= k) hi = mid;
        else lo = mid+1;
    }
    cout << lo;
}