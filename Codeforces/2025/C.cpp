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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        ll p1 = 0, p2 = 0;
        ll ans = 0;
        while(p1 < n){
            while(p2 + 1 < n && v[p2+1] - v[p1] < k && v[p2+1] <= v[p2] + 1) p2++;
            ans = max(ans, p2 - p1 + 1);
            if(p1 < p2) p1++;
            else p1++, p2++;
        }
        cout << ans << "\n";
    }
}
