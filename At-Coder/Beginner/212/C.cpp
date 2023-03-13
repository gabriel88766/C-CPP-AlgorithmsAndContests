#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int j=0;j<m;j++) cin >> b[j];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int bp = 0, ans = INF_INT;
    for(int i=0;i<n;i++){
        while(bp < m && b[bp] <= a[i]) bp++;
        int pos1 = (bp > 0 ? abs(b[bp-1]-a[i]) : INF_INT);
        int pos2 = (bp < m ? abs(b[bp] - a[i]) : INF_INT);
        ans = min(ans, min(pos1, pos2));
    }
    cout << ans;
}
