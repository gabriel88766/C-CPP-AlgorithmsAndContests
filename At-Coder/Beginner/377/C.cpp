#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, m;
    cin >> n >> m;
    ll ans = n*n;
    vector<pair<int,int>> vp;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
        for(int j=0;j<8;j++){
            int xd = a + dx[j];
            int yd = b + dy[j];
            if(xd >= 1 && xd <= n && yd >= 1 && yd <= n) vp.push_back({xd, yd});
        }
    }
    sort(vp.begin(), vp.end());
    vp.resize(unique(vp.begin(), vp.end()) - vp.begin());
    ans -= vp.size();
    cout << ans << "\n";
}
