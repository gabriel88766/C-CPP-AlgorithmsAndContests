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
    ll ans = 0;
    int n, m;
    cin >> n >> m;
    ll minv = 0, maxv = 0;
    for(int i=1;i<=n;i++) maxv += i-1;
    for(int i=1;i<=n;i++) minv += abs((n+1)/2 - i);
    for(int i=0;i<m;i++){
        ll x, d;
        cin >> x >> d;
        ans += x * n;
        if(d < 0){
            ans += minv * d;
        }else{
            ans += maxv * d;
        }
    }
    double x = ans;
    x /= n;
    cout << setprecision(6) << fixed << x << "\n";
}
