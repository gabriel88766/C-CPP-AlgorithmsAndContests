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
        int sz = n + m - 1;
        vector<vector<int>> v(sz+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x;
                cin >> x;
                v[i+j+1].push_back(x);
            }
        }
        int ans = 0;
        for(int i=1;i<=sz/2;i++){
            int c1 = 0, c0 = 0;
            for(auto x : v[i]){
                if(x == 1) c1++;
                else c0++;
            }
            for(auto x : v[sz-i+1]){
                if(x == 1) c1++;
                else c0++;
            }
            ans += min(c0, c1);
        }
        cout << ans << "\n";
    }
}
