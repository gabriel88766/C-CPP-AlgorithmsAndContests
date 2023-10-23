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
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> seg;
        set<int> edp;
        multiset<pair<int,int>> rmq;
        for(int i=1;i<=n;i++){
            int l, r;
            cin >> l >> r;
            seg.push_back({l,r});
            edp.insert(l);
        }
        sort(seg.begin(), seg.end());
        int ans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, p = 0;
        for(auto x : edp){
            while(p < n && seg[p].first == x){
                rmq.insert({seg[p].second, seg[p].first});
                if(seg[p].first == 1) cnt3++;
                if(seg[p].second == m) cnt2++;
                p++;
                cnt1++;
            }
            while(!rmq.empty() && rmq.begin()->first < x){
                if(rmq.begin()->second == 1) cnt3--;
                rmq.erase(rmq.begin());
                cnt1--;
            }
            int cur = cnt1;
            cur -= min(cnt2, cnt3);
            ans = max(ans, cur);
        }
        cout << ans << "\n";

    }
}
