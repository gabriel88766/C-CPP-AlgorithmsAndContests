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
        int n, r;
        cin >> n >> r;
        int ans = 0;
        int ca = 0, cf=0;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            cf += x/2;
            ca += x%2;
            ans += 2*(x/2);
        }
        int aux = 2*r - ans;
        ans += min(aux - ca, ca);
        cout << ans << "\n";
    }
}
