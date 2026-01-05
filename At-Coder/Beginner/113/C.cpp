#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt[100005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> vp;
    for(int i=0;i<m;i++){
        int p, y;
        cin >> p >> y;
        vp.push_back({y, p, i});
    }
    sort(vp.begin(), vp.end());
    vector<string> ans(m);
    for(auto [a, b, j] : vp){
        cnt[b]++;
        string a1 = to_string(b);
        string a2 = to_string(cnt[b]);
        a1 = string(6 - a1.size(), '0') + a1;
        a2 = string(6 - a2.size(), '0') + a2;
        ans[j] = a1 + a2;
        // cout << a1 << a2 << "\n";
    }
    for(auto x : ans) cout << x << "\n";
}
