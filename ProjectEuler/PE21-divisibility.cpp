#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> sdiv(10001);
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<=10000;i++){
        for(int j=2*i;j<=10000;j+=i){
            sdiv[j] += i;
        }
    }
    ll ans = 0;
    for(int i=1;i<=10000;i++){
        if(sdiv[i] != i && sdiv[sdiv[i]] == i) ans += i;
        if(i == sdiv[i]) cout << i << " ";
    }
    cout << ans << "\n";
}
