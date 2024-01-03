#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int aux[] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    
    int t;
    cin >> t;
    while(t--){
        int ans = 0;
        int n;
        cin >> n;
        for(int i=0;i<9;i++){
            for(int j=1;j<=9;j++){
                if(aux[i]*j <= n) ans++;
            }
        }
        cout << ans << "\n";
    }
}
