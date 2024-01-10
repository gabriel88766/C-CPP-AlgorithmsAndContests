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
    int s1 = 0, s2 = 0;
    s1 = (s[0]-'0') + (s[1] - '0') + (s[2] - '0');
    s2 = (s[3]-'0') + (s[4] - '0') + (s[5] - '0');
    int ans = 6;
    for(int i=0;i<=999999;i++){
        string cur;
        int aux = i;
        for(int j=0;j<6;j++){
            cur += (char)(aux % 10 + '0');
            aux /= 10;
        }
        int cch = 0;
        for(int j=0;j<6;j++){
            if(s[j] != cur[j]) cch++;
        }
        int s1 = (cur[0]-'0') + (cur[1]-'0') + (cur[2]-'0');
        int s2 = (cur[3]-'0') + (cur[4]-'0') + (cur[5]-'0');
        if(s1 != s2) continue;
        ans = min(ans, cch);
    }
    cout << ans << "\n";
}
