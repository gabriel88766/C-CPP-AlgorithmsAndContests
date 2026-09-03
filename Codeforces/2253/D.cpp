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
    //9=> x^2 + (k - x)^2 = k² + x² - 2kx + x² = 2x² - 2kx + k² minimum at x = -b/2a = k/2
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int x = 0, s = 0;
        while(s + x + 1 <= a + b) s += ++x;
        int diff = a + b - s;
        int d1 = diff/2;
        while(a - d1 < 0) d1--;
        while(b - (diff - d1) < 0) d1++;
        int d2 = diff - d1;
        int ga = a - d1, gb = b - d2;
        //cout << ga << " " << gb << "\n";
        string ans(x, 'X');
        for(int i=0;i<x;i++){
            if(gb >= x - i){
                gb -= x - i;
                ans[i] = 'Y';
            }
        }
        cout << ans << "\n";
    }
}
