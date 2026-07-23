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
    int n;
    cin >> n;
    vector<pair<int, int>> vp;
    for(int i=1;i<=n;i++){
        int h, l;
        cin >> h >> l;
        vp.push_back({h, l});
    }
    sort(vp.begin(), vp.end());
    int q;
    cin >> q;
    vector<pair<int, int>> qr;
    vector<int> ans(q+1);
    for(int i=1;i<=q;i++){
        int t;
        cin >> t;
        qr.push_back({t, i});
    }
    sort(qr.begin(), qr.end());
    for(auto [t, j] : qr){
        while(vp.size() && vp.back().second <= t) vp.pop_back();
        assert(vp.size());
        ans[j] = vp.back().first;
    }
    for(int i=1;i<=q;i++) cout << ans[i] << "\n";
}
