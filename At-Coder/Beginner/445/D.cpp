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
    int h, w, n;
    cin >> h >> w >> n;
    set<tuple<int, int, int>> s1, s2;
    for(int i=1;i<=n;i++){
        int ch, cw;
        cin >> ch >> cw;
        s1.insert({ch, cw, i});
        s2.insert({cw, ch, i});
    }
    vector<pair<int, int>> ans(n+1);
    for(int i=1;i<=n;i++){
        if(get<0>(*prev(s1.end())) == h){
            auto [ch, cw, i] = *prev(s1.end());
            s1.erase({ch,cw,i});
            s2.erase({cw,ch,i});
            ans[i] = {h - ch + 1, w - cw + 1};
            w -= cw;
        }else if(get<0>(*prev(s2.end())) == w){
            auto [cw, ch, i] = *prev(s2.end());
            s1.erase({ch,cw,i});
            s2.erase({cw,ch,i});
            ans[i] = {h - ch + 1, w - cw + 1};
            h -= ch;
        }else{
            // cout << i << " " << h << " " << w << " " << get<0>(*prev(s1.end())) << " " << get<0>(*prev(s2.end())) << endl;
            assert(false);
        }
    }
    for(int i=1;i<=n;i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}   
