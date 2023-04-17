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
    vector<int> ps1(n+1, 0), ps2(n+1, 0);
    for(int i=1;i<=n;i++){
        cin >> ps1[i];
        ps1[i] += ps1[i-1];
    }
    for(int i=1;i<=n;i++){
        cin >> ps2[i];
        ps2[i] += ps2[i-1];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, ps1[i] + ps2[n]-ps2[i-1]);
    }
    cout << ans;
}
