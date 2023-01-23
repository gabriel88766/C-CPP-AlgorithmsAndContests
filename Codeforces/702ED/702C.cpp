#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int p1 = 0, maxn = 0, n,m;
    cin >> n >> m;
    vector<int> c(n), t(m);
    for(int i=0;i<n;i++) cin >> c[i];
    for(int i=0;i<m;i++) cin >> t[i];

    for(int i=0;i<n;i++){
        while((p1+1 < m) && abs(t[p1+1] - c[i]) <= abs(t[p1] - c[i])) p1++;
        maxn = max(maxn, abs(t[p1] - c[i]));
    }
    cout << maxn;
}
