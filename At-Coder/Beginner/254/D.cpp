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
    int n;
    cin >> n;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        int num = i, mt = 1;
        for(int j=2;j*j<=num;j++){
            int ct = 0;
            while(!(num % j)){
                num /= j;
                ct++;
            }
            if(ct % 2){
                mt *= j;
            }
        }
        if(num != 1){
            mt *= num;
        }
        for(int k=1;k*k<=n/mt;k++) ans++;
    }
    cout << ans << "\n";
}
