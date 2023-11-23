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
        int h = n/2;
        vector<int> cnt(2*k+2, 0);
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        for(int i=1;i<=h;i++){
            int v1 = v[i];
            int v2 = v[n-i+1];
            int sum = v1 + v2;
            int l = min(v1+1, v2+1);
            int r = max(v1+k, v2+k);
            cnt[1] += 2;
            cnt[l] -= 1;
            cnt[sum] -= 1;
            cnt[sum+1] += 1;
            cnt[r+1] += 1;
        }
        for(int i=2;i<=2*k;i++) cnt[i] += cnt[i-1];
        int ans = 2*h;
        for(int i=1;i<=2*k;i++){
            ans = min(ans, cnt[i]);
        }
        cout << ans << "\n";
    }
}
