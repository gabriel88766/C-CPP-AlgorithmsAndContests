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
    double ans = 0;
    for(int i=0;i<s.size();i++){
        for(int j=i+2;j<s.size();j++){
            if(s[i] == 't' && s[j] == 't'){
                double cur = 0;
                for(int k=i+1;k<j;k++) if(s[k] == 't') cur++;
                cur /= (j-i-1);
                ans = max(ans, cur);
            }
        }
    }
    cout << fixed << setprecision(15) << ans << "\n";
}
