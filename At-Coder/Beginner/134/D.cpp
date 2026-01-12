#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int a[N], b[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int ans = 0;
    for(int i=n;i>=1;i--){
        int cnt = 0;
        for(int j=2*i;j<=n;j+=i) cnt ^= b[j];
        if(cnt != a[i]) b[i] = 1, ans++;
    }
    cout << ans << "\n";
    for(int i=1;i<=n;i++){
        if(b[i]) cout << i << " ";
    }
    cout << "\n";

}
