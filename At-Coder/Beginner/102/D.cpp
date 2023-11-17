#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll max(ll a, ll b, ll c, ll d){
    return max(max(a,b), max(c,d));
}
ll min(ll a, ll b, ll c, ll d){
    return min(min(a,b), min(c,d));
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> ps(n+1, 0);
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        ps[i] = ps[i-1] + v[i];
    }
    ll ans = INF_LL;
    for(int i=2;i<=n-2;i++){
        // 1 to i and i+1 to n
        int lo1 = 1, hi1 = i-1;
        while(lo1 != hi1){
            int mid = lo1 + (hi1 - lo1 + 1) / 2;
            if(ps[mid] < ps[i]-ps[mid]) lo1 = mid;
            else hi1 = mid - 1;
        }
        int lo2 = i+1, hi2 = n-1;
        while(lo2 != hi2){
            int mid = lo2 + (hi2 - lo2 + 1) / 2;
            if(ps[mid] - ps[i] < ps[n] - ps[mid]) lo2 = mid;
            else hi2 = mid - 1;
        }
        for(int j=0;j<=1;j++){
            if(lo1 + j == i) continue;
            for(int k=0;k<=1;k++){
                if(lo2 + k == n) continue;
                ll v1 = ps[lo1+j], v2 = ps[i]-ps[lo1+j], v3 = ps[lo2+k] - ps[i], v4 = ps[n] - ps[lo2+k];
                ans = min(ans, max(v1,v2,v3,v4) - min(v1,v2,v3,v4));
            }
        }
    }
    cout << ans << "\n";
}
