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
        int d;
        cin >> d;
        if(d >= 1 && d <= 3) cout << "N\n";
        else{
            ll dlt = d*d - 4*d;
            assert(dlt >= 0);
            double a = (d + sqrt(dlt));
            a /= 2;
            double b = d - a;
            cout << "Y ";
            cout << fixed << setprecision(14) << a <<  " " << b << "\n";
        }
    }
}
