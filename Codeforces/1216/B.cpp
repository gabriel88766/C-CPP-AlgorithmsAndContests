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
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first;
        vp[i].second = i;
    }
    sort(vp.begin(), vp.end(), greater<pair<int,int>>());
    ll ans = 0;
    vector<int> ansv(n);
    for(int i=0;i<n;i++){
        ans += vp[i].first*i+1;
        ansv[i] = vp[i].second+1;
    }
    cout << ans << "\n";
    for(auto x : ansv) cout << x << " ";
    cout << "\n";
}  