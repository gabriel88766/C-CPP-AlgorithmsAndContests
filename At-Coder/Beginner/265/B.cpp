#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
int a[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    ll t;
    cin >> n >> m >> t;
    for(int i=1;i<=n-1;i++) cin >> a[i];
    for(int i=1;i<=m;i++){
        int x, y;
        cin >> x >> y;
        a[x] -= y;
    }
    bool ok = true;
    for(int i=1;i<=n-1;i++){
        t -= a[i];
        if(t <= 0) ok = false;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
