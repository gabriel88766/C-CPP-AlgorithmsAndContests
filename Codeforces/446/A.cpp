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
    vector<int> v(n+2);
    vector<int> lgr(n+2), lgl(n+2);
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++){
        if(v[i] > v[i-1]) lgl[i] = lgl[i-1] + 1;
        else lgl[i] = 1;
    }
    for(int i=n;i>=1;i--){
        if(v[i] < v[i+1]) lgr[i] = lgr[i+1] + 1;
        else lgr[i] = 1;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(v[i+1] > v[i-1] + 1) ans = max(ans, lgl[i-1] + lgr[i+1] + 1);
        else ans = max({ans, lgl[i-1] + 1, lgr[i+1] + 1});
    }
    cout << ans << "\n";
}
