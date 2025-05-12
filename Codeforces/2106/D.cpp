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
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m), pr(n), su(n+1);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<m;i++) cin >> b[i];
        for(int i=0;i<n;i++){
            int op = i == 0 ? 0 : pr[i-1];
            if(op < m && b[op] <= a[i]) pr[i] = op + 1;
            else pr[i] = op;
        }
        su[n] = m-1;
        for(int i=n-1;i>=0;i--){
            int op = su[i+1];
            if(op >= 0 && b[op] <= a[i]) su[i] = op - 1;
            else su[i] = op;
        }
        if(pr[n-1] == m) cout << "0\n";
        else{
            int ans = INF_INT;
            for(int i=0;i<n;i++){
                if(pr[i] == su[i+1]) ans = min(ans, b[pr[i]]);
            }
            if(su[0] == 0) ans = min(ans, b[0]);
            if(ans == INF_INT) ans = -1;
            cout << ans << "\n";
        }
    }
}
