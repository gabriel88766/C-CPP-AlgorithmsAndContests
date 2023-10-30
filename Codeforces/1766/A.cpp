#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ans[1000005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<=999999;i++){
        int aux = i;
        while(!(aux % 10)) aux /= 10;
        if(aux < 10) ans[i]++;
        ans[i] += ans[i-1];
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }
}
