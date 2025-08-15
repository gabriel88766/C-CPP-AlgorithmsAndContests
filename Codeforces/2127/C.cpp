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
        int n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> vx(n);
        for(int i=0;i<n;i++) cin >> vx[i].first;
        for(int i=0;i<n;i++) cin >> vx[i].second;
        for(int i=0;i<n;i++){
            if(vx[i].first > vx[i].second) swap(vx[i].first, vx[i].second);
        }
        sort(vx.begin(), vx.end());
        ll ans = 0, mn = INF_LL;
    
        for(int i=0;i<n;i++){
            ans += vx[i].second - vx[i].first;
            if(i >= 1) mn = min(mn, vx[i].first - vx[i-1].second);
        }
        mn = max(mn, 0LL);
        ans += 2*mn;
        cout << ans << "\n";
    }
}
