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
        cout << 2*n - 1 << "\n";
        cout << "1 1 " << n << "\n";
        for(int i=2;i<=n;i++){
            cout << i << " " << 1 << " " << i-1 << "\n";
            cout << i << " " << i << " " << n << "\n";
        }
    }
}
