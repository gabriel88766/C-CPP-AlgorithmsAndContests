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
    int a = 1, b = 2;
    for(int i=2;i<=25;i++){
        ll ans1, ans2;
        cout << "? " << 1 << " " << i << "\n";
        cout.flush();
        cin >> ans1;
        cout << "? " << i << " " << 1 << "\n";
        cout.flush();
        cin >> ans2;
        if(ans1 == -1){
            cout << "! " << i-1 << "\n";
            cout.flush();
            break;
        }
        if(ans1 != ans2){
            cout << "! " << ans1+ans2 << "\n";
            cout.flush();
            break;
        }
    }
}
