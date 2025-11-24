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
    freopen("in", "r", stdin); //test input
    freopen("out", "w", stdout); //test input
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int n, m;
        cin >> n >> m;
        bool ok;
        if(n < m) ok = false; 
        else if(n < 2*m - 2) ok = true;
        else if(n % 2 == 0) ok = true;
        else ok = false;
        cout << "Case #" << i << ": ";
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
