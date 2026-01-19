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
    int n;
    cin >> n;
    ll mx[2][2];
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) mx[i][j] = -INF_LL;
    for(int i=1;i<=n;i++){
        ll x, y;
        cin >> x >> y;
        mx[0][0] = max(mx[0][0], -x-y);
        mx[0][1] = max(mx[0][1], -x+y);
        mx[1][0] = max(mx[1][0], x-y);
        mx[1][1] = max(mx[1][1], x+y);
    }
    cout << max(mx[1][1] + mx[0][0], mx[1][0] + mx[0][1]) << "\n";
}   
