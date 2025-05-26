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
        vector<int> v(n+1);
        int ans = 0, mx = 0;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            if(v[i] >= 2*mx){
                for(int j=1;j<i;j++) ans = max(ans, (v[i] % v[j]) + (v[j] % v[i]));
                mx = v[i];
            }else if(v[i] > mx){
                ans = mx = v[i];
            }else ans = max(ans, (v[i] % mx) + (mx % v[i]));
            cout << ans << " ";
        }
        cout << "\n";
    }
}
