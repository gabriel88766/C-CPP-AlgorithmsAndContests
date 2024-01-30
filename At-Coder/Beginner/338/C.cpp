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
    int n;
    cin >> n;
    vector<int> q(n);
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) cin >> q[i];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    int ans = 0;
    for(int i=0;;i++){
        auto qt = q;
        bool ok = true;
        for(int j=0;j<n;j++){
            qt[j] -= i*a[j];
            if(qt[j] < 0) ok = false;
        }
        if(!ok) break;
        int i2 = INF_INT;
        for(int j=0;j<n;j++){
            if(b[j]) i2 = min(i2, qt[j]/b[j]);
        }
        ans = max(ans, i + i2);
    }
    cout << ans << "\n";
}
