#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

char op[] = {'0', '2', '4', '6', '8'};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string ans;
    ll n;
    cin >> n;
    n--;
    while(n){
        ans += op[n%5];
        n /= 5;
    }
    if(ans.size() == 0) ans = "0";
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}
