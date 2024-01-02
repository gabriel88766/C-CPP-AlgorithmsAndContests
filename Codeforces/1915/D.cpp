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
        cin >> n >> s;
        string ans;
        ans += s[0];
        for(int i=1;i<n;i++){
            if(i == n-1) ans += s[i];
            else{
                if(s[i] == 'b' || s[i] == 'c' || s[i] == 'd'){
                    if(s[i+1] == 'b' || s[i+1] == 'c' || s[i+1] == 'd'){
                        ans += s[i];
                    }else{
                        ans += '.';
                        ans += s[i];
                    }
                }else ans += s[i];
            }
        }
        cout << ans << "\n";
    }
}
