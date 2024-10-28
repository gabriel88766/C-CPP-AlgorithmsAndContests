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
        int n;
        cin >> n;
        if(n == 1 || n == 3) cout << "-1\n";
        else if(n % 2){
            string ans(n, '3');
            ans[n-1] = ans[n-2] = ans[n-4] = '6';
            cout << ans << "\n";
        }else{
            string ans(n, '3');
            ans[n-1] = ans[n-2] = '6';
            cout << ans << "\n";
        }
    }
}
