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
    int n, p, q, r, s;
    cin >> n >> p >> q >> r >> s;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=p;i<=q;i++){
        swap(a[i], a[i-p+r]);
    }
    for(int i=1;i<=n;i++) cout << a[i] << " ";
    cout << "\n";
}
