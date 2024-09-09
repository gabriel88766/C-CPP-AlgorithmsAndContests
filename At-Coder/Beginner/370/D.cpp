#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 4e5+1;
set<int> rw[N], cw[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            rw[i].insert(j);
            cw[j].insert(i);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int r, c;
        cin >> r >> c;
        auto it1 = rw[r].lower_bound(c);
        auto it2 = cw[c].lower_bound(r);
        if(it1 != rw[r].end() && *it1 == c){
            rw[r].erase(c);
            cw[c].erase(r);
        }else{
            //four 
            //left right
            vector<pair<int,int>> rml;
            if(it1 != rw[r].end()){
                rml.push_back({r, *it1});
            }
            if(it1 != rw[r].begin()){
                rml.push_back({r, *prev(it1)});
            }
            if(it2 != cw[c].end()){
                rml.push_back({*it2, c});
            }
            if(it2 != cw[c].begin()){
                rml.push_back({*prev(it2), c});
            }
            for(auto [rr, cc] : rml){
                rw[rr].erase(cc);
                cw[cc].erase(rr);
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=h;i++) ans += rw[i].size();
    cout << ans << "\n";
}
