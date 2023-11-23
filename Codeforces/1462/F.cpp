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
        vector<pair<int,int>> p(n);
        for(int i=0;i<n;i++) cin >> p[i].first >> p[i].second;
        sort(p.begin(), p.end());
        vector<int> l(n, 0),  r(n, 0);
        multiset<int> ms;
        for(int i=0;i<n;i++){
            while(ms.size() && *ms.begin() < p[i].first) ms.erase(ms.begin());
            r[i] = ms.size();
            ms.insert(p[i].second);
        }
        for(int i=0;i<n;i++){
            auto ind = lower_bound(p.begin(), p.end(), make_pair(p[i].second, INF_INT)) - p.begin() - i - 1;
            l[i] = ind;
        }
        int ans = n-1;
        for(int i=0;i<n;i++){
            int x = n - l[i] - r[i] - 1;
            ans = min(ans, x);
        }
        cout << ans << "\n";
    }
}
