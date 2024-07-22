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
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int d1 = abs(x2-x1);
    int d2 = abs(y2-y1);
    int d3 = abs(x3-x2);
    int d4 = abs(y3-y2);
    int d5 = abs(x1-x3);
    int d6 = abs(y1-y3);
    int l1 = d1*d1 + d2*d2;
    int l2 = d3*d3 + d4*d4;
    int l3 = d5*d5 + d6*d6;
    if(l1 == l2 + l3 || l2 == l1+l3 || l3 == l1+l2) cout << "Yes\n";
    else cout << "No\n";
}
