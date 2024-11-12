#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll sum(ll l, ll r){
    return ((r+l) * (r-l+1))/2;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> x(m);
    for(int i=0;i<m;i++) cin >> x[i].first;
    for(int i=0;i<m;i++) cin >> x[i].second;
    sort(x.begin(), x.end());
    int ls = n+1;
    ll ans = 0;
    ll ss = 0;
    for(int i=m-1;i>=0;i--){
        int r = ls - 1;
        int l = max(r - x[i].second + 1, x[i].first);
        assert(l <= r);
        ss += x[i].second;
        ans += sum(l-x[i].first, r-x[i].first);
        ls = l;
    }
    if(ls == 1 && ss == n) cout << ans << "\n";
    else cout << "-1\n";
}
