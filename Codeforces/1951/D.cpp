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
        ll n, k;
        cin >> n >> k;
        if(k <= (n+1)/2){
            cout << "YES\n";
            cout << "2\n"; 
            cout << n - (k-1) << " " << 1 << "\n";
        }else if(n == k){
            cout << "YES\n1\n1\n";
        }else cout << "NO\n";
    }
}
