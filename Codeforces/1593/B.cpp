#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string cs[] = {"00", "52", "05", "57"};
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
        reverse(s.begin(), s.end());
        int ans = INF_INT;
        for(int i=0;i<4;i++){
            int fd = -1, sd = -1;
            for(int j=0;j<s.size();j++){
                if(fd == -1){
                    if(s[j] == cs[i][0]){
                        fd = j;
                    }
                }else{
                    if(s[j] == cs[i][1]){
                        sd = j;
                        break;
                    }
                }
            }
            if(sd != -1) ans = min(ans, sd-1);
        }
        cout << ans << "\n";
    }
}
