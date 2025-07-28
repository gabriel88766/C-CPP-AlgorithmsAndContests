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
    //approach maximize overflows
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        ll ans = 0;
        for(int i=0;i<n;i++) ans += a[i] + b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int lo = 0, hi = n;
        while(lo != hi){
            int mid = lo + (hi - lo + 1)/2;
            //impairing from n-mid to n-1
            bool ok = true;
            for(int i=n-mid;i<=n-1;i++){
                int j = n - 1 - (i - (n-mid));
                if(a[i] + b[j] < m) ok = false;
            }
            if(ok) lo = mid;
            else hi = mid - 1;
        }
        // cout << lo << " ";
        ans -= lo * m;
        cout << ans << "\n";
    }
}
