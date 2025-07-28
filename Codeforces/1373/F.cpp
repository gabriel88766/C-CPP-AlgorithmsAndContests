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
        vector<ll> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        vector<ll> r(n);
        for(int i=0;i<n;i++){
            r[i] = b[i] - a[i];
        }
        int lw = 0;
        ll ps = 0, lps = 0;
        for(int i=0;i<n;i++){
            ps += r[i];
            if(ps < lps){
                lps = ps;
                lw = i+1;
            }
        }
        if(ps < 0) cout << "NO\n";
        else{
            bool ok = true;
            ll cb = 0;
            // cout << lw << " ";
            for(int j = lw;j<lw+n;j++){
                int i = j % n;
                // cout << j << " " << cb << " " << r[i] << "\n";
                if(cb + r[i] < 0){
                    ok = false;
                }else{
                    cb = min((cb + r[i]), b[i]);
                }
            }
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
