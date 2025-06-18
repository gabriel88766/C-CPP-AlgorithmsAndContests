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
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    for(int i=0;i<x;i++) cin >> a[i];
    for(int i=0;i<y;i++) cin >> b[i];
    for(int i=0;i<z;i++) cin >> c[i];
    ll lo = 0, hi = 30'000'000'001LL;
    //find the first number such that there are less than k sums greater than or equal to lo
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    sort(c.begin(), c.end(), greater<ll>());
    while(lo != hi){
        ll mid = lo + (hi - lo)/2;
        ll tt = 0;
        for(int i=0;i<x;i++){
            int p = z-1;
            for(int j=0;j<y;j++){
                while(p >= 0 && a[i] + b[j] + c[p] < mid) p--;
                tt += p + 1;
            }
        }
        if(tt < k) hi = mid;
        else lo = mid + 1;
    }
    vector<ll> ans;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                if(a[i] + b[j] + c[k] >= lo) ans.push_back(a[i] + b[j] + c[k]);
                else break;
            }
        }
    }
    sort(ans.begin(), ans.end(), greater<ll>());
    ans.resize(k, lo-1);
    for(auto x : ans) cout << x << "\n";
}
