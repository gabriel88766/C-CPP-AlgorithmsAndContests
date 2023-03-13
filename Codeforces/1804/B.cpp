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
        ll n, k, d, w;
        cin >> n >> k >> d >> w;
        vector<ll> t(n);
        for(int i=0;i<n;i++) cin >> t[i];

        if(k == 1){
            cout << n << "\n";
            continue;
        }

        int mc = 0;
        int ans = 0;
        int md = w+d;
        int cnt = 1;

        for(int i=1;i<n;i++){
            if(md >= t[i]-t[mc]) cnt++;
            else{
                ans++;
                mc = i;
                cnt = 1;
            }
            if(cnt == k){
                ans++;
                cnt = 0;
                mc = i+1;
            }
        }
        if(cnt) ans++;
        cout << ans << "\n";
    }
}
