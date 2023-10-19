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
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    bool ok1 = false;
    bool ok2 = false;
    if(s == t.substr(0, n)) ok1 = true;
    if(s == t.substr(m-n, n)) ok2 = true;
    int p = 0;
    if(!ok2) p |= 1;
    if(!ok1) p |= 2;
    cout << p << "\n";
}
