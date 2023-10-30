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
        if(n >= 10){
            //1, 2, 7// 1,2,8//1,4,7//1,2,10
            int x = 2, y = n-3;
            if(!(y%3)){
                x += 2;
                y -= 2;
            } 
            cout << "YES\n" << 1 << " " << x << " " << y << "\n";
        }else if(n == 7 || n == 8){
                cout << "YES\n1 2 " << n-3 << "\n"; 
        }else cout << "NO\n";
    }
}
