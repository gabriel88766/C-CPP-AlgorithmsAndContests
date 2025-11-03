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
        vector<int> cnt(4*n+1);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            cnt[x]++;
        }
        for(int i=1;i<=4*n;i++) cnt[i] += cnt[i-1];
        int ans = 0;
        for(int i=1;i<=n;i++){
            int tt = cnt[4*i - 1] - cnt[3*i] + cnt[3*i-1] - cnt[2*i] + cnt[2*i-1] - cnt[i] + cnt[i-1];
            if(tt <= k) ans = i;
        }
        cout << ans << "\n";
    }
}
