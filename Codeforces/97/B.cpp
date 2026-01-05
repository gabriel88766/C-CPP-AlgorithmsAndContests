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
    vector<pair<int, int>> pts(n);
    set<pair<int, int>> usd;
    for(int i=0;i<n;i++){
        cin >> pts[i].first >> pts[i].second;
        usd.insert(pts[i]);
    }
    sort(pts.begin(), pts.end());
    function<void(int,int)> solve = [&](int l, int r){
        if(l >= r) return; //already ok
        int m = (l + r) / 2;
        int m1 = m, m2 = m;
        while(m1 - 1 >= l && pts[m1 - 1].first == pts[m].first) m1--;
        while(m2 + 1 <= r && pts[m2 + 1].first == pts[m].first) m2++;
        set<int> nd;
        for(int i=l;i<m1;i++) nd.insert(pts[i].second);
        for(int i=m2+1;i<=r;i++) nd.insert(pts[i].second);
        for(auto x : nd){
            usd.insert({pts[m].first, x});
        }
        solve(l, m1-1);
        solve(m2+1, r);
    };
    solve(0, n-1);
    cout << usd.size() << "\n";
    for(auto [a, b] : usd) cout << a << " " << b << "\n";
}
