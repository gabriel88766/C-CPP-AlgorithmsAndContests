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
    set<int> s1 = {1,3,5,7,8,10,12};
    set<int> s2 = {4,6,9,11};
    int x, y;
    cin >> x >> y;
    if(s1.count(x) && s1.count(y)) cout << "Yes";
    else if(s2.count(x) && s2.count(y)) cout << "Yes";
    else cout << "No";
}
