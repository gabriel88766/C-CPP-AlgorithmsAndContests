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
    int n, p, l, r;
    cin >> n >> p >> l >> r;
    if(l == 1 && r == n) cout << "0\n";
    else if(l == 1){
        cout << abs(r-p) + 1 << "\n";
    }else if(r == n){
        cout << abs(l-p) + 1 << "\n";
    }else{
        int d2 = r - l + 2;
        cout << min(abs(l-p), abs(r-p)) + d2 << "\n"; 
    }
}
