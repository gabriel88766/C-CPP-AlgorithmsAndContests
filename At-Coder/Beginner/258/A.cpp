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
    if(k < 10) cout << "21:0" << k << "\n";
    else if(k < 60) cout << "21:" << k << "\n";
    else if(k < 70) cout << "22:0" << k-60 << "\n";
    else cout << "22:" << k-60 << "\n";
}
