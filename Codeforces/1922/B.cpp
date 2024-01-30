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
        vector<ll> cnt(n+1);
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            cnt[x]++;
        }
        ll ps = 0, ans = 0;
        for(int i=0;i<=n;i++){
            if(cnt[i] >= 2){
                ans += ps * ((cnt[i] * (cnt[i]-1))/2);
            }
            if(cnt[i] >= 3){
                ans += (cnt[i] * (cnt[i] - 1) * (cnt[i] - 2))/6;
            }
            ps += cnt[i];
        }
        cout << ans << "\n";
    }
}   
