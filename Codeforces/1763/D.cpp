#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, i, j, x, y;
        cin >> n >> i >> j >> x >> y;
        if(x > y){
            if(y > (n-j + i)){
                cout << "0\n";
            }
        }else{
            if(x < i || y < j || (y-x) < (j-i)){
                cout << "0\n" << t <<"\n";
            }else{

            }
        }
    }
}
