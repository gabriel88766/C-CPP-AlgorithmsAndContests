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
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        int ans = s1.size() + s2.size();
        for(int i=0;i<2;i++){
            swap(s1, s2);
            for(int j=1;j<=s1.size();j++){
                if(s1.substr(0, j) == s2.substr(0, j)){
                    int cur = s1.size() + s2.size() + 1 - j;
                    ans = min(ans, cur);
                }
            }
        }
        cout << ans << "\n";
    }
}
