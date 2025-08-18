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
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<ll> a(n+1), b(m+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> b[i];
    int p0 = 1, p1 = 1;
    vector<pair<int, int>> ans;
    while(p0 <= n && p1 <= m){
        if(b[p1] >= a[p0] - x && b[p1] <= a[p0] + y){
            ans.push_back({p0++, p1++});
        }else if(b[p1] < a[p0] - x) p1++;
        else if(b[p1] > a[p0] + y) p0++;
    }
    cout << ans.size() << "\n";
    for(auto [a, b] : ans) cout << a << " " << b << "\n";
}
