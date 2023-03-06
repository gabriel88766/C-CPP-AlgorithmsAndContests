#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s, t;
    cin >> s;
    int cnt = 0, cnt2 = 0;
    t = s[0];
    for(int i=1;i<s.size();i++){
        if(s[i] == s[i-1]){
            cnt++;
            if(cnt == 1) t += s[i];
        }else{
            cnt = 0;
            t += s[i];
        }
    }
    string ans;
    ans = t[0];
    cnt = 0;
    for(int i=1;i<t.size();i++){
        if(t[i] == t[i-1]){
            cnt++;
            cnt2 = 0;
            if(cnt%2) ans += t[i];
        }else{
            cnt2++;
            ans += t[i];
            if(cnt2 > 1) cnt = 0;
        }
    }
    cout << ans;
}