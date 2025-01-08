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
        ll cs = n, cng = 0, ans = 0;
        vector<pair<int,int>> evs; // 1 is negative, 2 is don't buy
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            evs.push_back({x+1, 1});
        }
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            evs.push_back({x+1, 2});
        }
        int p = 0;
        sort(evs.begin(), evs.end());
        ans = cs * (evs[0].first - 1);
        while(p < evs.size()){
            int p2 = p;
            while(p2 + 1 < evs.size() && evs[p2+1].first == evs[p].first) p2++;
            for(int i=p;i<=p2;i++){
                auto [a, b] = evs[i];
                if(b == 1) cng++;
                else cng--, cs--;
            }
            p = p2 + 1;
            if(cng <= k && cs > 0){
                assert(p < evs.size());
                ll cur = evs[p].first - 1;
                ans = max(ans, cur * cs);
            }
        }
        cout << ans << "\n";
    }
}
