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
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if(r1 == r2 && c1 == c2) cout << "0\n";
    else if(r1+c1 == r2+c2 || r1-c1 == r2-c2 || abs(r1-r2) + abs(c1-c2) <= 3) cout << "1\n";
    else if(abs(r1-r2) % 2 == abs(c1-c2) % 2) cout << "2\n";
    else if(abs(abs(r1-r2) - abs(c1-c2)) <= 3) cout << "2\n";
    else if(abs(r1-r2) + abs(c1-c2) <= 6) cout << "2\n";
    else cout << "3\n";
}
