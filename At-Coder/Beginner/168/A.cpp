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
    int x;
    cin >> x;
    int ans = x % 10;
    if(ans == 2 || ans == 4 || ans == 5 || ans == 7 || ans == 9) cout << "hon\n";
    else if(ans == 0 || ans == 1 || ans == 6 || ans == 8) cout << "pon\n";
    else cout << "bon\n";
}
