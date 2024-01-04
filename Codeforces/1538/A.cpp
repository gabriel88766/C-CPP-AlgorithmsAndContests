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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int p1 = min_element(v.begin(), v.end()) - v.begin();
        int p2 = max_element(v.begin(), v.end()) - v.begin();
        reverse(v.begin(), v.end());
        int p3 = min_element(v.begin(), v.end()) - v.begin();
        int p4 = max_element(v.begin(), v.end()) - v.begin();
        int ans = min(p1, p3) + min(p2, p4) + 2;
        ans = min(ans, min(max(p1, p2) + 1, max(p3, p4) + 1));
        cout << ans << "\n";
    }
}
