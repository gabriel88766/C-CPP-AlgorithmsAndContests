#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int get(int n){
    if(n == 1) return 0;
    else return get((n+1)/2) + 1;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int ans = INF_INT;
        ans = min(ans, get(a) + get(m) + 1);
        ans = min(ans, get(n-a+1) + get(m) + 1);
        ans = min(ans, get(b) + get(n) + 1);
        ans = min(ans, get(m-b+1) + get(n) + 1);
        cout << ans << "\n";
    }
}
