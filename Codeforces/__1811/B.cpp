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
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int u = min(min(x1, n-x1+1), min(y1, n-y1+1));
        int v = min(min(x2, n-x2+1), min(y2, n-y2+1));
        cout << abs(u-v) << "\n";
    }
}
