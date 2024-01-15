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
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        sort(v.begin()+1, v.end());
        int ans = -INF_INT;
        vector<int> ps(n+1);
        for(int i=1;i<=n;i++) ps[i] = ps[i-1] + v[i];
        for(int i=0;i<=k;i++){
            int cur = 0;
            if(n-i >= x){
                int neg = ps[n-i] - ps[n-i-x];
                int pos = ps[n-i-x];
                cur = pos - neg;
            }else{
                cur = -ps[n-i];
            }
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
}
