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
        sort(v.begin(), v.end());
        ll ans = 0;
        for(int i=0;i<n;i++){ //greatest
            int p = 0;
            int sa = min(-v[i], v[i] - v.back()); //bob choose the best possible based on the greatest
            for(int j=i-1;j>=1;j--){ //mid element
                while(p < j && sa + v[j] + v[p] <= 0) p++;
                if(p == j) break;
                ans += j - p;
            }
        }
        cout << ans << "\n";
    }
}
