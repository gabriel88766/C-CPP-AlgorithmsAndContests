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
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    ll lo = 0, hi = 1'000'000'001;
    while(lo != hi){
        ll mid = lo + (hi - lo + 1)/2;
        ll cur = 0;
        for(int i=0;i<n;i++){
            cur += min(v[i], mid);
        }
        if(cur <= m) lo = mid;
        else hi = mid - 1;
    }
    if(lo != 1'000'000'001) cout << lo << "\n";
    else cout << "infinite\n";
}
