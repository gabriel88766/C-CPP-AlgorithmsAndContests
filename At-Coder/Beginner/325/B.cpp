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
    vector<int> w(n), x(n);
    for(int i=0;i<n;i++) cin >> w[i] >> x[i];
    int ans = 0, cur = 0;
    for(int i=0;i<24;i++){
        cur = 0;
        for(int j=0;j<n;j++){
            int pl = x[j] - i;
            if(pl < 0) pl += 24;
            if(pl >= 9 && pl < 18) cur += w[j];
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}
