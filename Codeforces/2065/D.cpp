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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> v[i][j];
            }
        }
        sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b){
            ll sa = 0, sb = 0;
            for(auto &x : a) sa += x;
            for(auto &x : b) sb += x;
            return sa > sb;
        });
        ll ans = 0;
        ll ps = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ps += v[i][j];
                ans += ps;
            }
        }
        cout << ans << "\n";
    }
}
