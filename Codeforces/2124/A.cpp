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
        int lx = -1;
        bool ok = false;
        pair<int, int> ans;
        for(int i=1;i <= n;i++){
            int x;
            cin >> x;
            if(x < lx){
                ok = true;
                ans ={lx, x};
            }
            lx = x;
        }
        if(ok) cout << "YES\n" << "2\n" << ans.first << " " << ans.second << "\n";
        else cout << "NO\n";
    }
}
