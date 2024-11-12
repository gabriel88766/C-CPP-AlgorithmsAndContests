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
        int n, m, val;
        cin >> n >> m >> val;
        vector<int> v(n+1), pr(n+1), su(n+2);
        vector<ll> ps(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        int s = 0;
        for(int i=n;i>=1;i--){
            s += v[i];
            if(s >= val){
                su[i] = 1;
                s = 0;
            }
            su[i] += su[i+1];
        }
        s = 0;
        for(int i=1;i<=n;i++){
            s += v[i];
            if(s >= val){
                pr[i] = 1;
                s = 0;
            }
            ps[i] = ps[i-1] + v[i];
            pr[i] += pr[i-1];
        }
        ll ans = -1;
        if(pr[n] >= m){
            for(int i=1;i<=n;i++){
                int cur = pr[i-1];
                if(cur < m){
                    int r = n+1;
                    for(int j=n/2;j>=1;j>>=1){
                        while(r - j >= 1 && su[r-j] + cur < m) r -= j;
                    }
                    r-=2;
                    if(r >= i-1) ans = max(ans, ps[r] - ps[i-1]);
                    
                }else{
                    ans = max(ans, ps[n] - ps[i-1]);
                }
            }
        }
        cout << ans << "\n";
    }
}
