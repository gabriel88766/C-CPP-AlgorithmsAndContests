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
    bool ok = true;
    int n, m;
    cin >> n >> m;
    int t;
    cin >> t;
    int ct = 0;
    int cb = n;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        cb -= (a - ct);
        if(cb <= 0) ok = false;
        cb += (b - a);
        cb = min(cb, n);
        ct = b;
    }
    cb -= (t - ct);
    if(cb <= 0) ok = false;
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
