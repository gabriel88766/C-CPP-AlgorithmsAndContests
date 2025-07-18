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
    reverse(s.begin(), s.end());
    int cg = 0, cm = 1;
    map<int, int> mp;
    mp[0] = 1;
    ll ans = 0;
    for(int i=0;i<s.size();i++){
        cg += (s[i] - '0') * cm;
        cg %= 2019;
        ans += mp[cg]++;
        cm = (10 * cm) % 2019;
    }
    cout << ans << "\n";
}
