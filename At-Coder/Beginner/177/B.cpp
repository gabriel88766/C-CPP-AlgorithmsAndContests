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
    string s, t;
    cin >> s >> t;
    int ans = INF_INT;
    for(int i=0;i<=s.size()-t.size();i++){
        int cur = 0;
        for(int j=0;j<t.size();j++){
            if(s[i+j] != t[j]) cur++;
        }
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}
