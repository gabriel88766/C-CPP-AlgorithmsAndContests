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
        vector<int> a(n), b(n), c(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        for(int i=0;i<n;i++) cin >> c[i];
        ll ans = n;
        ll cur = 0;
        for(int i=0;i<n;i++){
            bool ok = true;
            for(int j=0;j<n;j++){
                int ci = j + i >= n ? j + i - n : j + i;
                if(a[ci] >= b[j]) ok = false;
            }
            if(ok) cur++;
        }
        ans *= cur;
        cur = 0;
        for(int i=0;i<n;i++){
            bool ok = true;
            for(int j=0;j<n;j++){
                int ci = j + i >= n ? j + i - n : j + i;
                if(b[ci] >= c[j]) ok = false;
            }
            if(ok) cur++;
        }
        ans *= cur;
        cout << ans << "\n";
    }
}
