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
    string s,t;
    int n, k, dif = 0;
    cin >> k >> s >> t;
    n = s.size();
    for(int i=0;i<n;i++) if(s[i] != t[i]) dif++;
    cout << min(n-dif, k) + min(dif, n-k);
}
