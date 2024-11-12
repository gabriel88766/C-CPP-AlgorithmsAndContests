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
    reverse(s.begin(), s.end());
    vector<ll> vn(n+1, 0);
    for(int i=0;i<n;i++){
        int cd = s[i] - '0';
        vn[i] += cd * (n-i);
    }
    for(int i=n-2;i>=0;i--) vn[i] += vn[i+1];
    string ans = "";
    for(int i=0;i<n;i++){
        int cd = vn[i] % 10;
        ans += (char)('0' + cd);
        vn[i+1] += vn[i] / 10;
    }
    assert(vn[n] < 10);
    if(vn[n] != 0) ans += (char)('0' + vn[n]);
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}
