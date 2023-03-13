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
    ll N, S, T, A, B;
    cin >> N >> S >> T >> A >> B;
    ll minv;
    double ans = 1e300;
    if(S <= T) ans = (T-S)*A;
    
    ans = min(ans, (double)N*B);
    ll opt1 = sqrtl(((double)2*N*B)/A) + EPS;
    ll opt2 = opt1 + 1;

    if(opt1 > T) opt1 = T;


    double opt1d = ((double)(B*N))/opt1 + ((double)(opt1-1)*A)/2;
    double opt2d = opt2 <= T ? ((double)(B*N))/opt2 + ((double)(opt2-1)*A)/2 : 1e300;

    ans = min(ans, min(opt1d, opt2d));





    cout << fixed << setprecision(15) << ans;
}
