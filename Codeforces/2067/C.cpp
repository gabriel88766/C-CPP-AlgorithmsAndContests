#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<ll> mdf = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999LL, 99999999999LL};
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
        s += "0";
        int ans = 10;
        ll aux1 = 0, aux2 = 1;
        for(int i=0;i<s.size();i++){
            if(i != 0){
                int nd;
                if(s[i] <= '7') nd = '7' - s[i];
                else nd = '7' - s[i] + 10;
                if(nd <= aux1) ans = min(ans, nd);
                else ans = min(ans, nd + 1);

                //but...
                if(s[i] == '8') ans = min((ll)ans, aux1+1);

                aux1 += (s[i] - '0') * aux2;
            }else{
                if(s[i] >= '7') ans = (s[i] - '7');
                else ans = 10 + (s[i] - '7');
                aux1 += s[i] - '0';
            }
            aux2 *= 10;
        }
        cout << ans << "\n";

    }
}
