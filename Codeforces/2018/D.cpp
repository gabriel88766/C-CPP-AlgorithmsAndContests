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
        vector<pair<int,int>> vp;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            vp.push_back({x, i});
        }
        sort(vp.begin(), vp.end(), greater<pair<int,int>>());
        int mx = vp[0].first;
        int ans = 0;
        int cur = 0, p = 0, cnt = 0;
        set<tuple<int,int,int>> s;
        set<int> s0, s1;
        for(auto [x, j] : vp){
            if(x != mx) break;
            if(j % 2) s1.insert(j);
            else s0.insert(j);
        }
        for(int mn = mx; mn >= mx-n; mn--){
            while(p < vp.size() && vp[p].first == mn){
                int j = vp[p].second;
                int mni = j, mxi = j;
                auto it = s.lower_bound(make_tuple(j, 0 ,0));
                vector<tuple<int,int,int>> rml;
                if(it != s.end() && get<0>(*it) == (j+1)){
                    auto [l, r, ps] = *it;
                    rml.push_back(*it);
                    cur -= (r-l+2)/2;
                    mxi = r;
                    cnt -= ps;
                }
                if(it != s.begin() && get<1>(*prev(it)) == (j-1)){
                    auto [l, r, ps] = *prev(it);
                    rml.push_back(*prev(it));
                    cur -= (r - l + 2)/2;
                    mni = l;
                    cnt -= ps;
                }
                cur += (mxi - mni + 2)/2;
                for(auto x:rml) s.erase(x);
                
                p++;
                int lo = INF_INT, le = INF_INT;
                auto it2 = s1.lower_bound(mni);
                if(it2 != s1.end()) lo = *it2;
                auto it3 = s0.lower_bound(mni);
                if(it3 != s0.end()) le = *it3;
                if((mxi - mni + 1) % 2){
                    if(mni % 2){
                        if(lo <= mxi){
                            s.insert({mni, mxi, 1});
                            cnt++;
                        }else s.insert({mni, mxi, 0});
                    }else{
                        if(le <= mxi){
                            s.insert({mni, mxi, 1});
                            cnt++;
                        }else s.insert({mni, mxi, 0});
                    }
                }else{
                    if(lo <= mxi || le <= mxi){
                        cnt++;
                        s.insert({mni, mxi, 1});
                    }else s.insert({mni, mxi, 0});
                }
            }
            
            ll curs = mn + mx + cur;
            //need to check if at least 1 "mx" is choosable
            if(cnt) ans = max(ans, mn + mx + cur);
            else ans = max(ans, mn + mx + cur-1);
        }
        

        cout << ans << "\n";

    }
}
