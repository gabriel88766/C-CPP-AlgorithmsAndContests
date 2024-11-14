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
    string s;
    cin >> s;
    if(s == "Monday") cout << 5 << "\n";
    else if(s == "Tuesday") cout << 4 << "\n";
    else if(s == "Wednesday") cout << 3 << "\n";
    else if(s == "Thursday") cout << 2 << "\n";
    else cout << 1 << "\n";
}
