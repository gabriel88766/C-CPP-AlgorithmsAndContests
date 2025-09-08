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
    set<string> s1 = {"RGB", "GBR", "BRG"};
    set<string> s2 = {"RBG", "GRB", "BGR"};
    string t1(3, '.'), t2(3, '.');
    cin >> t1[0] >> t1[1] >> t1[2];
    cin >> t2[0] >> t2[1] >> t2[2];
    if(s1.count(t1) && s1.count(t2)) cout << "Yes\n";
    else if(s2.count(t1) && s2.count(t2)) cout << "Yes\n";
    else cout << "No\n";
}
