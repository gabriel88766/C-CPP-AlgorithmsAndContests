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
    int n;
    string s;
    cin >> n >> s;
    ll ans = 0;
    int c0 = 1, c1 = 0, cnt = 0;
    for(auto c : s){
        if(c == '0') cnt++;
        if(cnt % 2) ans += c1++;
        else ans += c0++;
    }
    cout << ans << "\n";
}
