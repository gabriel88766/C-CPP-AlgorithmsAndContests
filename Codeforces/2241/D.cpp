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
        vector<ll> a(n+1), b(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        bool ok = true;
        for(int i=1;i<n;i++){
            ll diff = b[i] - a[i];
            if(diff < 0){
                ok = false;
                break;
            }
            a[i+1] -= diff;
        }
        if(a[n] <= b[n] && ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
