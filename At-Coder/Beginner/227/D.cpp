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
    vector<ll> v(n);
    ll sum = 0;
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) sum += v[i];
    ll ans = sum / k;
    ll lo = 1, hi = ans;
    while(lo != hi){
        ll sum = 0;
        ll mid = lo + (hi-lo+1)/2;
        for(int i=0;i<n;i++) sum += min(mid, v[i]);
        if(sum >= mid*k) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}      
