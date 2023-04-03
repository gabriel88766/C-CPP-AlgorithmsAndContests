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
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        int ans = n;
        for(int i=0;i<n-1;i++){
            bool ok = true;
            int maxseg = i+1;
            int sum = 0;
            for(int j=0;j<=i;j++) sum += a[j];
            int cs = 0, li = i+1;
            for(int j=i+1;j<n;j++){
                cs += a[j];
                if(cs > sum){
                    ok = false; break;
                }else if(cs == sum){
                    maxseg = max(maxseg, j-li+1);
                    li = j+1;
                    cs = 0;
                }
            }
            if(cs != 0) ok = false;
            if(ok) ans = min(ans, maxseg);
        }
        cout << ans << "\n";
    }
}
