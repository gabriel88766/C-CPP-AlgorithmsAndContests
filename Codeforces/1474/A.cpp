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
        int n;
        string s;
        string ans;
        cin >> n >> s;
        int l = -1;
        for(int i=0;i<n;i++){
            if(l == 1 || l == 2){
                if(l == 1){
                    if(s[i] == '1') ans += '1', l = 2;
                    else ans += '0', l = 0;
                }else{
                    if(s[i] == '1') ans += '0', l = 1;
                    else ans += '1', l = 1; 
                }
            }else{
                ans += '1';
                l = 1 + s[i] - '0';
            }
        }
        cout << ans << "\n";
    }
}
