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
    vector<pair<int, int>> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i].first;
    for(int i=1;i<=n;i++) cin >> v[i].second;
    sort(v.begin(), v.end());
    vector<int> vs;
    int cur = 0;
    for(int i=1;i<=n;i++){
        cur = max(cur, v[i].first);
        vs.push_back(cur);
        ++cur;
    }
    multiset<int> ms;
    ll cc = 0;
    int p = 0;
    ll ans = 0;
    for(auto x : vs){
        while(p < v.size() && v[p].first <= x){
            ms.insert(v[p].second);
            cc += v[p].second;
            p++;
        }
        cc -= *prev(ms.end());
        ms.erase(prev(ms.end()));
        ans += cc;
    }
    cout << ans << "\n";
}
