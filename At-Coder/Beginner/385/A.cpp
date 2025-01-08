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
    int v[3];
    cin >> v[0] >> v[1] >> v[2];
    sort(v, v+3);
    if(v[0] == v[2]) cout << "Yes\n";
    else if(v[0] + v[1] == v[2]) cout << "Yes\n";
    else cout << "No\n";
}
