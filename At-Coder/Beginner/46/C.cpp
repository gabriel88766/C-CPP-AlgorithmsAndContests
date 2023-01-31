#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, a=1, b=1, inp1, inp2;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> inp1 >> inp2;
        ll da, db, maxd;
        da = a/inp1 + (a % inp1 ? 1:0);
        db = b/inp2 + (b % inp2 ? 1:0);
        maxd = max(da,db);
        a = inp1 * maxd;
        b = inp2 * maxd;
    }
    cout << a+b;
}
