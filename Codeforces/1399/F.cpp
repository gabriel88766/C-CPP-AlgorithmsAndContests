#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> xv[6005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ord(n+1);   
        vector<int> dp(n+1);
        iota(ord.begin(), ord.end(), 0);
        vector<pair<int, int>> seg(n+1);
        seg[0] = {0, 200001};
        vector<int> vals;
        vals.push_back(0);
        vals.push_back(200001);
        for(int i=1;i<=n;i++){
            cin >> seg[i].first >> seg[i].second;
            vals.push_back(seg[i].first);
            vals.push_back(seg[i].second);
        }
        sort(vals.begin(), vals.end());
        vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
        assert(vals.size() <= 6002);
        for(auto &[a, b] : seg){
            a = lower_bound(vals.begin(), vals.end(), a) - vals.begin();
            b = lower_bound(vals.begin(), vals.end(), b) - vals.begin();
        }
        sort(seg.begin(), seg.end());

        sort(ord.begin(), ord.end(), [&](int a, int b){
            int sz1 = seg[a].second - seg[a].first + 1;
            int sz2 = seg[b].second - seg[b].first + 1;
            if(sz1 != sz2) return sz1 < sz2;
            else return seg[a].first < seg[b].first;
        });
        for(auto j : ord){
            int mx = 0, aux = 0;
            for(int i=0;i<6005;i++) xv[i].clear();
            int p = 0;
            for(int i=0;i<seg.size();i++){
                if(i == j) continue;
                if(seg[i].first < seg[j].first || seg[i].second > seg[j].second) continue;
                //i is in j
                while(p < seg[i].first){
                    for(auto x : xv[p]) aux = max(aux, x);
                    p++;
                }
                int cur = aux + dp[i];
                mx = max(mx, cur);
                xv[seg[i].second].push_back(cur);
            }


            dp[j] = mx + 1;
        }
        cout << dp[0] - 1 << "\n";
    }
}
