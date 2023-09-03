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
    int len = s.size();
    int ans = 0;
    for(int i=1;i<len;i++){
        for(int j=0;j<len-i+1;j++){
            for(int k=j+1;k<len-i+1;k++){
                if(s.substr(j, i) == s.substr(k, i)){
                    ans = i;
                }
            }
        }
    }
    cout << ans << "\n";
}
