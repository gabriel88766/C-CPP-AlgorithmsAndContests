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
    cout << "?";
    for(int i=0;i<100;i++){
        cout << " " << i;
    }
    cout << "\n";
    cout.flush();
    int hi;
    cin >> hi;
    hi >>= 7;
    hi <<= 7;
    cout << "?";
    for(int i=1;i<=100;i++){
        cout << " " << i * (1 << 7);
    }
    cout << "\n";
    cout.flush();
    int lo;
    cin >> lo;
    lo &= 0x7F;
    cout << "! " << hi+lo << "\n";
    cout.flush();
}
