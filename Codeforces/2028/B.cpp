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
        ll n, b, c;
        cin >> n >> b >> c;
        if(b > 0){
            //count number of elements greater than or equal to n
            if(c >= n) cout << n << "\n";
            else{
                ll x = (n-c-1)/b;
                assert(x < n);
                cout << n - x - 1 << "\n";    
            }
        }else if(n-1 <= c+1){
            if(c < n) cout << n-1 << "\n";
            else cout << n << "\n";
        }else cout << "-1\n";
    }
}
