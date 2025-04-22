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
        int n;
        cin >> n;
        vector<vector<tuple<int, int, int>>> vp(n+1);
        vector<int> ans(n+1, INF_INT);
        for(int i=0;i<n;i++){
            int l, r, c;
            cin >> l >> r >> c;
            vp[c].push_back({l, r, i});
        }
        multiset<int> s1, s2;
        for(int i=1;i<=n;i++){
            for(auto &[l, r, x] : vp[i]){
                s1.insert(l);
                s2.insert(r);
            }
        }
        vector<tuple<int, int, int, int>> vx;
        for(int i=1;i<=n;i++){
            for(auto &[l, r, x] : vp[i]){
                vx.push_back({l, r, i, x});
                s1.erase(s1.find(l));
                s2.erase(s2.find(r));
            }
            for(auto &[l, r, x] : vp[i]){
                auto it = s1.lower_bound(l);
                if(it != s1.end()) ans[x] = min(ans[x], max(0, *it - r));
                auto it2 = s2.upper_bound(r);
                if(it2 != s2.begin()) ans[x] = min(ans[x], max(0, l - *prev(it2))); 
            }
            for(auto &[l, r, x] : vp[i]){
                s1.insert(l);
                s2.insert(r);
            }
        }
        sort(vx.begin(), vx.end());
        s1.clear();
        multiset<pair<int, int>> rem;
        for(auto &[l, r, i, x] : vx){
            while(rem.size() && rem.begin()->first < l){
                s1.erase(s1.find(rem.begin()->second));
                rem.erase(rem.begin());
            }
            if(s1.size() && (*s1.begin() != i || *prev(s1.end()) != i)) ans[x] = 0;
            s1.insert(i);
            rem.insert({r, i});
        }
        for(int i=0;i<n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
