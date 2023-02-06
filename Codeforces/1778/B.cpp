#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n,m,d;
        cin >> n >> m >> d;
        vector<int> p(n), pos(n+1);
        for(int i=0;i<n;i++) {
            cin >> p[i];
            pos[p[i]] = i+1;
        }
        vector<int> a(m);
        for(int i=0;i<m;i++) cin >> a[i];
        int ans = INF_INT;
        for(int i=1;i<m;i++){
            int dif1 = pos[a[i]] - pos[a[i-1]];
            int dif2 = pos[a[i-1]] - pos[a[i]] + d;
            ans = min(ans, max(0, dif1));
            if((d+1) < n) ans = min(ans, max(0, dif2+1));
        }
        cout << ans << "\n";
    }
}
