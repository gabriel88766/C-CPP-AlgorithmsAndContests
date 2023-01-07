#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    vector<pair<int,int>> vp;
    ll ans = 0, curt = 0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,d;
        cin >> a >> d;
        vp.push_back({a,d});
    }
    sort(vp.begin(), vp.end());
    for(int i=0;i<n;i++){
        curt += vp[i].first;
        ans += vp[i].second - curt;
    }
    cout << ans;
}
