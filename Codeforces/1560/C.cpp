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
        int k;
        cin >> k;
        int x = sqrt(k);
        while(x*x > k) x--;
        while((x+1)*(x+1) <= k) x++;
        if(x*x == k) cout << x << " 1\n";
        else{
            int r = k - x*x - 1;
            int a = 1, b = x+1;
            if(r > x){
                r -= x;
                a += x;
                b -= r;
            }else{
                a += r;
            }
            cout << a << " " << b << "\n";
        }
    }
}
