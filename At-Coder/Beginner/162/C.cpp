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
    int k;
    cin >> k;
    ll s = 0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int u=1;u<=k;u++){
                int x = gcd(i, j);
                x = gcd(x, u);
                s += x;
            }
        }
    }
    cout << s << "\n";
}   
