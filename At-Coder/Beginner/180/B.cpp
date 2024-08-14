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
    ll s1 = 0, s2 = 0, s3 = 0;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        ll x;
        cin >> x;
        s1 += abs(x);
        s2 += x*x;
        s3 = max(abs(x), s3);
    }
    cout << setprecision(15) << s1 << " " << sqrt(s2) << " " << s3 << "\n";
}
