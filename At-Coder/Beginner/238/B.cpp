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
    vector<int> cut;
    cut.push_back(0);
    int cur = 0;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        cur += x;
        cur %= 360;
        cut.push_back(cur);
    }
    sort(cut.begin(), cut.end());
    cut.resize(unique(cut.begin(), cut.end()) - cut.begin());
    cut.push_back(360);
    int ans = 0;
    for(int i=1;i<cut.size();i++) ans = max(ans, cut[i] - cut[i-1]);
    cout << ans << "\n";
}
