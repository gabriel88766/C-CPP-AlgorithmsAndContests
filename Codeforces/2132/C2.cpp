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
    vector<pair<ll, ll>> nums;
    ll cn = 1;
    for(int i=0;i<=18;i++){
        nums.push_back({cn, cn * 3 + i * (cn/3)});
        cn *= 3;
    }
    int t;
    cin >> t;
    // reverse(nums.begin(), nums.end());
    while(t--){
        ll n, k;
        cin >> n >>  k;
        // ll ans = 
        vector<ll> ans = {n};
        auto sum = [&](){
            ll ax = 0;
            for(auto x : ans) ax += x;
            return ax;
        };
        while(true){
            if(sum() <= k) break;
            else if(ans.back() < 3) break;
            else{
                if(ans.back()/3 + ans.back() % 3 + sum() - ans.back() <= k){
                    ll lo = 0, hi = ans.back() / 3;
                    ll bk = ans.back();
                    while(lo != hi){
                        ll mid = lo + (hi - lo)/2;
                        if( sum() - 2*mid <= k) hi = mid;
                        else lo = mid + 1;
                    }
                    ans.back() -= 3 * lo;
                    ans.push_back(lo);
                    break;
                }else{
                    ll rm = ans.back() % 3;
                    ll nw = ans.back() / 3;
                    ans.back() = rm;
                    ans.push_back(nw);
                }
            }
        }
        if(sum() <= k){
            ll rans = 0;
            for(int i=0;i<ans.size();i++){
                rans += ans[i] * nums[i].second;
                // cout << ans[i] << " " << nums[i].second << "\n";
            }
            cout << rans << "\n";
        }else cout << "-1\n";
    }
}
