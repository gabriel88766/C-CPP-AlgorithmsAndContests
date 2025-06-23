#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int fat[11];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    fat[1] = 1;
    for(int i=2;i<=10;i++) fat[i]  = fat[i-1] * i;
    int n;
    cin >> n;
    int ans = 0;
    for(int i=10;i>=1;i--){
        while(n >= fat[i]){
            ans++;
            n -= fat[i];
        }
    }
    cout << ans << "\n";
}
