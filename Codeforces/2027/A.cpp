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
        int m1 = 0, m2 = 0;
        for(int i=1;i<=n;i++){
            int x, y;
            cin >> x >> y;
            m1 = max(m1, x);
            m2 = max(m2, y);
        }
        cout << 2 * (m1 + m2) << "\n";
    }
}
