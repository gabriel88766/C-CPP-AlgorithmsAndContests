#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ans[180];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=3;i<=360;i++){
        for(int j=1;j<=i-2;j++){
            int ca = j*180;
            if(ca % i) continue;
            ca /= i;
            if(!ans[ca]) ans[ca] = i;
        }
    }
    for(int i=1;i<180;i++) assert(ans[i]);
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
}
