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
    int n, y;
    cin >> n >> y;
    y /= 1000;
    for(int i=0;i<=n;i++){
        for(int j=0;j+i<=n;j++){
            int k = n-i-j;
            if((10*i + 5*j + k) == y){
                cout << i << " " << j << " " << k << "\n";
                return 0;
            }
        }
    }
    cout << "-1 -1 -1";
}
