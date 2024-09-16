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
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++) cin >> vp[i].first;
        for(int i=0;i<n;i++) cin >> vp[i].second;
        sort(vp.begin(), vp.end());
        int b1 = -1, b0 = -1;
        for(int i=0;i<n;i++){
            if(vp[i].second == 1) b1 = i;
            else b0 = i;
        }
        ll ans = -1;
        //check if choose b1
        //n = 5 => pm = 1, n = 6 => pm = 2
        if(b1 != -1){
            int pm = (n-2)/2;
            if(pm >= b1) pm++;
            ans = k;
            ans += vp[b1].first;
            ans += vp[pm].first;
        }
        if(b0 != -1){
            ll ans2 = vp[b0].first;
            ll lo = 1, hi = 2e9+1;
            while(lo != hi){
                ll mid = lo + (hi - lo + 1)/2;
                int qt = 0;
                ll ak = k;
                for(int i=n-1;i>=0;i--){
                    if(i == b0) continue;
                    if(vp[i].second == 0){
                        if(vp[i].first >= mid) qt++;
                    }else{
                        if(vp[i].first + ak >= mid){
                            qt++;
                            if(vp[i].first < mid) ak -= mid - vp[i].first;
                        }
                    }
                }
                if(qt >= n - qt) lo = mid;
                else hi = mid - 1;
            }
            ans = max(ans, ans2 + lo);
        }
        cout << ans << "\n";
        

    }
}
