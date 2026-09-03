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
        int cur = 0, ans = 0, lx = -1;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            if(x == lx || x + lx == 7) cur++;
            else cur = 0;
            lx = x;
            if(cur % 2 == 1) ans++;
        } 
        cout << ans << "\n";
    }
}
