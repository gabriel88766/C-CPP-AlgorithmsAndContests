#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
ll ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, c, q;
    cin >> h >> w >> c >> q;
    map<int, pair<int,int>> mp1, mp2;
    for(int i=1;i<=q;i++){
        int t, n, c;
        cin >> t >> n >> c;
        if(t == 1) mp1[n] = {i, c};
        else mp2[n] = {i, c};
    }
    vector<pair<int,int>> vp1, vp2;
    for(auto [n, par] : mp1){
        auto [t, c] = par;
        vp1.push_back({t, c});
    }
    for(auto [n, par] : mp2){
        auto [t, c] = par;
        vp2.push_back({t, c});
    }
    sort(vp1.begin(), vp1.end());
    sort(vp2.begin(), vp2.end());
    for(auto [t, c] : vp1){
        int qt = vp2.end() - lower_bound(vp2.begin(), vp2.end(), make_pair(t, 0));
        ans[c] += w - qt;
    }
    for(auto [t, c] : vp2){
        int qt = vp1.end() - lower_bound(vp1.begin(), vp1.end(), make_pair(t, 0));
        ans[c] += h - qt;
    }
    for(int i=1;i<=c;i++) cout << ans[i] << " ";
    cout << "\n";

}
