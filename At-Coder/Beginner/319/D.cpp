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
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for(int j=0;j<n;j++) cin >> v[j];
    ll lo = *max_element(v.begin(), v.end()), hi = 1e18;
    while(lo != hi){
        ll mid = lo + (hi - lo)/2;
        int p = 0;
        ll cl = 0;
        while(p < n){
            ll cnt = -1;
            while(p < n && cnt + v[p] + 1 <= mid){
                cnt += v[p++] + 1;
            }
            cl++;
        }
        if(cl <= m) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";

}
