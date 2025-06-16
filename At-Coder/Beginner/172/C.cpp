#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll ps1[N], ps2[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> ps1[i];
        ps1[i] += ps1[i-1];
    }
    for(int i=1;i<=m;i++){
        cin >> ps2[i];
        ps2[i] += ps2[i-1];
    }
    int p2 = m;
    int ans = 0;
    for(int i=0;i<=n;i++){
        if(ps1[i] > k) break;
        while(ps2[p2] + ps1[i] > k) p2--;
        ans = max(ans, p2 + i);
    }
    cout << ans << "\n";
}
