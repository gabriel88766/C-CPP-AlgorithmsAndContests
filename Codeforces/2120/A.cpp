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
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        // vector<vector<int>> ps = {{3}, {2, 1}, {1, 2}, {1, 1, 1}};
        // bool ok = false;
        if(l1 == l2 && l2 == l3 && b1+b2+b3 == l1) cout << "YES\n";
        else if(b1 == b2 && b2 == b3 && l1+l2+l3 == b1) cout << "YES\n";
        else if(b1 == b2 + b3 && l2 == l3 && l1 + l2 == b1) cout << "YES\n";
        else if(l1 == l2 + l3 && b2 == b3 && b1 + b2 == l1) cout << "YES\n";
        else cout << "NO\n";
    }
}
