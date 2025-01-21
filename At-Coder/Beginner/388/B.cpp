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
    int n, d;
    cin >> n >> d;
    vector<int> t(n), l(n);
    for(int i=0;i<n;i++) cin >> t[i] >> l[i];
    for(int i=1;i<=d;i++){
        int ans = 0;
        for(int j=0;j<n;j++){
            ans = max(ans, t[j] * (l[j] + i));
        }
        cout << ans << "\n";
    }
}
