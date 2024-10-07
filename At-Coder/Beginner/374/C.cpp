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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int ans = INF_INT;
    for(int j=0;j<(1 << n);j++){
        int a1 = 0, a2 = 0;
        for(int k=0;k<n;k++){
            if(j & (1 << k)) a1 += v[k];
            else a2 += v[k];
        }
        ans = min(ans, max(a1, a2));
    }
    cout << ans << "\n";
}
