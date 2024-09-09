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
    int p0 = 0, p1 = n-1;
    while(p0+1 < n && s[p0+1] == s[0]) p0++;
    while(p1-1 >= 0 && s[p1-1] == s.back()) p1--;
    ll q1 = p0 + 1;
    ll q2 = n - p1;
    if(s[0] == s.back()){    
        ans = ((q1+1)*(q2+1)) % MOD;
    }else{
        ans = (q1+1) + (q2 + 1) - 1;
    }
    cout << ans << "\n";
}
