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
    int x[5], y[5], px[5], py[5];
    for(int i=0;i<4;i++) cin >> x[i] >> y[i];
    x[4] = x[0];
    y[4] = y[0];
    for(int i=0;i<4;i++){
        px[i] = x[i+1] - x[i];
        py[i] = y[i+1] - y[i];
    }
    px[4] = px[0];
    py[4] = py[0];
    int p = 0, n = 0;
    for(int i=0;i<4;i++){
        int cur = px[i] * py[i+1] - px[i+1] * py[i];
        if(cur > 0) p++;
        if(cur < 0) n++;
    }
    // cout << p << " " << n << "\n";
    if(p > 0 && n > 0) cout << "No\n";
    else cout << "Yes\n";
}
