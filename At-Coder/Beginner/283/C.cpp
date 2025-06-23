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
    int ans = 1;
    int p = 1;
    while(p < s.size()){
        if(s[p] == '0'){
            if(p+1 < s.size() && s[p+1] == '0'){
                p += 2;
                ans++;
            }else{
                p++;
                ans++;
            }
        }else{
            ans++;
            p++;
        }
    }
    cout << ans << "\n";
}
