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
        int n;
        cin >> n;
        vector<int> v(n);
        vector<bool> pos(1 << 8, false);
        pos[0] = true;
        for(int i=0;i<n;i++) cin >> v[i];
        int ans = 0, cur = 0;
        for(int i=0;i<n;i++){
            cur ^= v[i];
            for(int j=0;j<(1 << 8);j++){
                if(pos[j]){
                    ans = max(ans, j^cur);
                }
            }
            pos[cur] = true;
        }
        cout << ans << "\n";
    }
}
