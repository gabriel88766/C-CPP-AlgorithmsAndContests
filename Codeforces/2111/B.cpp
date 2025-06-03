#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int fib[11];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    fib[1] = 1;
    fib[2] = 2;
    for(int i=3;i<=10;i++) fib[i] = fib[i-1] + fib[i-2];
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        for(int i=0;i<m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            if(a >= fib[n] && b >= fib[n] && c >= fib[n]){
                if(a >= fib[n] + fib[n-1] || b >= fib[n] + fib[n-1] || c >= fib[n] + fib[n-1]){
                    cout << "1";
                }else cout << "0";
            }else cout << "0";
        }
        cout << "\n";
    }
}
