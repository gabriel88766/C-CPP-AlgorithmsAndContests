#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll pot3[50], pot5[50];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll cnt3 = 1, cnt5 = 1;
    const ll MAX_LL = 1000000000000000000LL;

    //init
    pot3[0] = pot5[0] = 1;
    for(int i=1;i<=100;i++){
        if(pot3[i-1] * 3 <= MAX_LL){
            cnt3 = i;
            pot3[i] = pot3[i-1] * 3;
        }else break;
    }
    for(int i=1;i<=100;i++){
        if(pot5[i-1] * 5 <= MAX_LL){
            cnt5 = i;
            pot5[i] = pot5[i-1] * 5;
        }else break;
    }
    ll n;
    cin >> n;
    for(int i=1;i<=cnt3;i++){
        for(int j=1;j<=cnt5;j++){
            if(n == pot3[i] + pot5[j]) {
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "-1";
}
