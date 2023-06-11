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
    map<char,int> mp = {{'A',0}, {'B',3}, {'C',4}, {'D',8}, {'E', 9}, {'F', 14}, {'G', 23}};
    char p, q;
    cin >> p >> q;
    cout << abs(mp[p]-mp[q]);
}
