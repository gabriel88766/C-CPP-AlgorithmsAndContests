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
        int mx = 0;
        for(int i=1;i<=n;i++) mx |= i; //can do faster, but whatever...
        vector<int> cnt(mx+1, 0);
        cnt[0] = 1;
        ll ans = n;
        ans *= (n+1);
        ans /= 2;
        int cx = 0;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            cx ^= x;
            for(int j=0;j*j<=mx;j++) ans -= cnt[cx ^ (j*j)];
            cnt[cx]++;
        }
        cout << ans << "\n";
    }
}
