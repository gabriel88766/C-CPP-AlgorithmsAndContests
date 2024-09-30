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
        string s;
        cin >> s;
        int ld = 0;
        int n = s.size();
        ll ans = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0') ld++;
            else{
                int cn = 0;
                for(int j=i;j<n;j++){
                    cn <<= 1;
                    if(s[j] == '1') cn++;
                    int len = j - i + 1 + ld;
                    if(len >= cn) ans++;
                    else break;
                }
                ld = 0;
            }
        }
        cout << ans << "\n";
    }
}
