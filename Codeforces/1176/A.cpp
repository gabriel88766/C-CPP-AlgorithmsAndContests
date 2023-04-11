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
        ll n;
        cin >> n;
        ll cnt2 = 0, cnt3 = 0, cnt5 = 0;
        while(!(n%2)){
            cnt2++;
            n /= 2;
        }
        while(!(n%3)){
            cnt3++;
            n /= 3;
        }
        while(!(n%5)){
            cnt5++;
            n /= 5;
        }
        if(n == 1){
            cout << (cnt2 + cnt3*2 + cnt5*3) << "\n";
        }else cout << "-1\n";
    }
}
