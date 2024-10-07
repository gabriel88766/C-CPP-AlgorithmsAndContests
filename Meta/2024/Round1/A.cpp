#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


bool ge(double a, double b){
    return a + EPS >= b;
}
bool le(double a, double b){
    return a - EPS <= b;
}
bool eq(double a, double b){
    return ge(a,b) && le(a,b);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("subsonic_subway_input.txt", "r", stdin); //test input
    freopen("out.txt", "w", stdout); //test input
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        int n;
        cin >> n;
        vector<pair<double, double>> ans(n);
        double mn = 0, mx = 1e18;
        for(int j=1;j<=n;j++){
            double a, b;
            cin >> a >> b;
            a = j / a;
            if(eq(b, 0.0)) b = 1e18;
            else b = j / b;
            mn = max(mn, b);
            mx = min(mx, a);
        }
        cout << "Case #" << i << ": ";
        if(ge(mx, mn)) cout << fixed << setprecision(10) << mn << "\n";
        else cout << "-1\n";

    }
}
