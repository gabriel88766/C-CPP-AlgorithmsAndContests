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
    int n, q;
    cin >> n >> q;
    int ans = n;
    vector<pair<int, int>> vqs;
    vector<int> cds;
    cds.push_back(1);
    for(int i=1;i<=q;i++){
        int l, r;
        cin >> l >> r;
        cds.push_back(l);
        cds.push_back(r+1);
        vqs.push_back({l, r});
    }
    sort(cds.begin(), cds.end());
    cds.resize(unique(cds.begin(), cds.end()) - cds.begin());
    set<int> in;
    map<int, int> ord;
    vector<int> val(cds.size());
    for(int i=0;i<cds.size();i++){
        in.insert(cds[i]);
        ord[cds[i]] = i;
        if(i != cds.size() - 1){
            val[i] = cds[i+1] - cds[i];
        }else{
            val[i] = n + 1 - cds[i];
        }
    }
    for(auto [l, r] : vqs){
        auto it = in.lower_bound(l);
        while(it != in.end() && *it <= r){
            ans -= val[ord[*it]];
            in.erase(it);
            it = in.lower_bound(l);
        }
        cout << ans << "\n";
    }

}
